using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.Runtime.InteropServices;

namespace ClassLibrary1
{
    [Guid("19C96E51-E5AE-46A2-ABE2-317D867C6958")]
    public interface Region
    {
        //public void logDate();
    }

    [ClassInterface(ClassInterfaceType.None)]
    [Guid("36EA856C-99E3-4365-B157-6C0D75173F48")]
    public class ConvertTo : Region
    {

        public static int koreanLunisolar(int year, int month, int day)
        {
            int ret = 0;
            DateTime date = Convert.ToDateTime(convertTo(year, month, day));
            KoreanLunisolarCalendar cal = new KoreanLunisolarCalendar();
            int Y = cal.GetYear(date);
            int M = cal.GetMonth(date);
            int D = cal.GetDayOfMonth(date);
            if (cal.GetMonthsInYear(Y) > 12)
            {
                int leapMonth = cal.GetLeapMonth(Y);
                if (M >= leapMonth)
                {
                    cal.IsLeapMonth(Y, M);
                    M--;
                }
            }
            ret = 10000 * Y + 100 * M + D;
            return ret;
        }

        private static String convertTo(int year, int month, int day)
        {
            //DateTime temp = new DateTime();
            String date = year.ToString();
            date += "-" + (month < 10 ? "0" + month.ToString() : month.ToString());
            date += "-" + (day < 10 ? "0" + day.ToString() : day.ToString());
            //date += " " + (temp.get)
            return date;
        }
    }
}
