using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace MedCalc
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void CalcRoom()
        {
            var dtStart = dtRoomIn.Value;
            var dtEnd = dtRoomOut.Value;

            if(dtEnd <= dtStart)
            {
                MessageBox.Show("结束时间要大于开始时间。");
                return;
            }

            var dtdiff = dtEnd - dtStart;
            tbTotalHour.Text = dtdiff.Value.TotalHours.ToString("F3");
        }

        private void bnCalcTotal_Click(object sender, RoutedEventArgs e)
        {
            CalcRoom();
        }
    }
}
