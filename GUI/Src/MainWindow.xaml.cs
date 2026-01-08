// @file MainWindow.xaml.cs
// @version 0.0.0.2
// @date 2026-1-8

using ImageCLR;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace GUI
{
	/// <summary>
	/// .2
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
			try {
				m_Image.LoadImage("Assets/Image/test.jpg");
				m_Wb = new WriteableBitmap(
					m_Image.Width, m_Image.Height,
					96, 96, PixelFormats.Bgr24, null);

				ImageMat.Source = m_Wb;

				m_Timer.Elapsed += (s, e) => RefreshFrame();
				m_Timer.Start();
			}
			catch(Exception ex) {
				MessageBox.Show(ex.Message, "error");
			}
		}
		private void MainWindow_OnClosed(object sender, EventArgs e) {
			m_Timer?.Stop();
			m_Timer?.Dispose();
		}
		private void RefreshFrame() {
			Array bufferPtr = m_Image.Data;
			Dispatcher.Invoke(() => {
				m_Wb.Lock();
				m_Wb.WritePixels(
					new Int32Rect(0, 0, m_Wb.PixelWidth, m_Wb.PixelHeight),
					bufferPtr,
					m_Image.Stride,
					0);
				m_Wb.Unlock();
			});
		}
	}
}