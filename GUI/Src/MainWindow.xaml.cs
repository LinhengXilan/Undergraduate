using System.Windows;
using System.Windows.Controls;
using System.Collections.Generic;
using System.Windows.Input;
using System.Windows.Media;
using ImageCLR;

namespace GUI
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public class ImageCanvas : Canvas {
		public List<List<ImageCLR.Point>> contours;
		protected override void OnRender(DrawingContext context) {
			Pen pen = new Pen(Brushes.Black, 5);
			foreach (List<ImageCLR.Point> contour in contours) {
				for (int i = 0; i < contour.Count; i++) {
					System.Windows.Point point1 = new System.Windows.Point(contour[i].X, contour[i].Y);
					System.Windows.Point point2;
					if (i == contour.Count - 1) {
						point2 = new System.Windows.Point(contour[0].X, contour[0].Y);
					}
					else {
						point2 = new System.Windows.Point(contour[i + 1].X, contour[i + 1].Y);
					}
					context.DrawLine(pen, point1, point2);
				}
			}
		}
	}
	public partial class MainWindow : Window {
		private ImageCanvas m_ImageCanvas = new ImageCanvas();
		private ContourFinder m_ContourFinder = new ContourFinder();
		public MainWindow() {
			InitializeComponent();
		}
		private void MainWindow_OnLoaded(object sender, RoutedEventArgs e) {
			try {
				m_ContourFinder.LoadImage("Assets/Image/test.jpg");
				m_ImageCanvas.Height = m_ContourFinder.Rows;
				m_ImageCanvas.Width = m_ContourFinder.Cols;
				m_ImageCanvas.contours = m_ContourFinder.FindContours(250);
				Viewbox_Image.Child = m_ImageCanvas;
				Viewbox_Image.InvalidateVisual();
			}
			catch(Exception ex) {
				MessageBox.Show(ex.Message, "error");
			}
		}

		private void TextBox_Threshold_OnKeyDown(object sender, KeyEventArgs e) {
			if (e.Key == Key.Enter) {
				
				int threshold = int.Parse(TextBox_Threshold.Text);
				m_ImageCanvas.contours = m_ContourFinder.FindContours(threshold);
				m_ImageCanvas.InvalidateVisual();
			}
		}
	}
}