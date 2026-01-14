// @file MainWindow.xaml.cs
// @version 0.0.0.5
// @date 2026-1-14

using ImageCLR;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace GUI
{
	public partial class MainWindow : Window {
		private readonly Processor m_Processor = new();
		private WriteableBitmap m_OriginalBitmap;
		private WriteableBitmap m_ProcessedBitmap;
		public MainWindow() {
			InitializeComponent();
		}
		private void MainWindow_OnLoaded(object sender, RoutedEventArgs e) {
			TextBoxOpenedFile.Text = "当前打开文件：";
		}
		private void ButtonClick_LoadImage(object sender, RoutedEventArgs e) {
			var dialog = new Microsoft.Win32.OpenFileDialog {
				FileName = String.Empty,
				Filter = "图像文件|*.jpg;*.png;*.bmp"
			};
			var result = dialog.ShowDialog();
			if (result != true) return;
			try {
				m_Processor.LoadImage(dialog.FileName);
			} catch (Exception ex) {
				MessageBox.Show(ex.Message, "无法加载图片");
			}
			TextBoxOpenedFile.Text = "当前打开文件：" + dialog.FileName;
			Display();
		}
		private void Display() {
			m_OriginalBitmap = new WriteableBitmap(m_Processor.Width, m_Processor.Height, 96, 96, PixelFormats.Bgr24, null);
			ImageOriginal.Width = m_Processor.Width / 2;
			ImageOriginal.Height = m_Processor.Height / 2;
			ImageOriginal.Source = m_OriginalBitmap;

			m_ProcessedBitmap = new WriteableBitmap(m_Processor.Width, m_Processor.Height, 96, 96, PixelFormats.Gray8, null);
			ImageProcessed.Width = m_Processor.Width / 2;
			ImageProcessed.Height = m_Processor.Height / 2;
			ImageProcessed.Source = m_ProcessedBitmap;
			if (m_Processor.IsProcessed) {
				m_ProcessedBitmap.WritePixels(new Int32Rect(0, 0, m_ProcessedBitmap.PixelWidth, m_ProcessedBitmap.PixelHeight), m_Processor.ProcessedData, m_Processor.Stride / 3, 0);
			}
			m_OriginalBitmap.WritePixels(new Int32Rect(0, 0, m_OriginalBitmap.PixelWidth, m_OriginalBitmap.PixelHeight), m_Processor.OriginalData, m_Processor.Stride, 0);
		}

		private void ButtonClick_Start(object sender, RoutedEventArgs e) {
			m_Processor.Start();
			Display();
		}

		private void ButtonClick_Stop(object sender, RoutedEventArgs e) {
			
		}
	}
}