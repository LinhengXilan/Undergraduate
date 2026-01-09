// @file MainWindow.xaml.cs
// @version 0.0.0.4
// @date 2026-1-9

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
		private void MainWindow_OnLoaded(object sender, RoutedEventArgs e) {
			TextBoxFileOpened.Text = "当前打开文件：";
		}
		private void MainWindow_OnClosed(object sender, EventArgs e) {
			m_Timer?.Stop();
			m_Timer?.Dispose();
		}
		private void OpenFileDialog_OnClick(object sender, RoutedEventArgs e) {
			var dialog = new Microsoft.Win32.OpenFileDialog {
				FileName = String.Empty,
				Filter = "图像文件|*.jpg;*.png;*.bmp"
			};
			var result = dialog.ShowDialog();

			if (result != true) {
				return;
			}

			try {
				TextBoxFileOpened.Text = "当前打开文件：" + dialog.FileName;
				m_Image.LoadImage(dialog.FileName);
				m_Wb = new WriteableBitmap(m_Image.Width, m_Image.Height, 96, 96, PixelFormats.Bgr24, null);
			} catch (Exception ex) {
				MessageBox.Show(ex.Message, "无法加载图片");
			}

			ImagePending.Width = m_Image.Width;
			ImagePending.Height = m_Image.Height;
			ImagePending.Source = m_Wb;
			RenderTransformPendingScale.ScaleX = 0.5;
			RenderTransformPendingScale.ScaleY = 0.5;
			m_Timer.Elapsed += (s, e) => RefreshFrame();
			m_Timer.Start();
		}
		private void RefreshFrame() {
			Array bufferPtr = m_Image.Data;
			Dispatcher.Invoke(() => {
				m_Wb.Lock();
				m_Wb.WritePixels(new Int32Rect(0, 0, m_Wb.PixelWidth, m_Wb.PixelHeight), bufferPtr, m_Image.Stride, 0);
				m_Wb.Unlock();
			});
		}
	}
}