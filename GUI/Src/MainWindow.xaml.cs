// @file MainWindow.xaml.cs
// @version 0.0.0.3
// @date 2026-1-8

using ImageCLR;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;


namespace GUI
{
	/// <summary>
	/// 
	/// </summary>
	public partial class MainWindow : Window {
		private readonly ImageCLR.Image m_Image = new();
		private readonly System.Timers.Timer m_Timer = new(30);
		private WriteableBitmap m_Wb;
		public MainWindow() {
			InitializeComponent();
		}
		private void MainWindow_OnClosed(object sender, EventArgs e) {
			m_Timer?.Stop();
			m_Timer?.Dispose();
		}
		private void RefreshFrame() {
			Array bufferPtr = m_Image.Data;
			Dispatcher.Invoke(() => {
				m_Wb.Lock();
				m_Wb.WritePixels(new Int32Rect(0, 0, m_Wb.PixelWidth, m_Wb.PixelHeight), bufferPtr, m_Image.Stride, 0);
				m_Wb.Unlock();
			});
		}

		private void OpenFileDialog_OnClick(object sender, RoutedEventArgs e) {
			var dialog = new Microsoft.Win32.OpenFileDialog();
			dialog.FileName = String.Empty;
			dialog.Filter = "图像文件|*.jpg;*.png;*.bmp";
			var result = dialog.ShowDialog();
			if (result == true) {
				try {
					Textbox_FilePath.Text = dialog.FileName;
					m_Image.LoadImage(dialog.FileName);
					m_Wb = new WriteableBitmap(m_Image.Width, m_Image.Height, 96, 96, PixelFormats.Bgr24, null);
				} catch (Exception ex) {
					MessageBox.Show(ex.Message, "无法加载图片");
				}
				Image_Pending.Width = m_Image.Width;
				Image_Pending.Height = m_Image.Height;
				Image_Pending.Source = m_Wb;
				Image_PendingScale.ScaleX = 0.5;
				Image_PendingScale.ScaleY = 0.5;
				m_Timer.Elapsed += (s, e) => RefreshFrame();
				m_Timer.Start();
			}
		}
	}
}