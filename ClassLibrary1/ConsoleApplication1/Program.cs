using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.Runtime.InteropServices;

namespace ConsoleApplication1
{
    [Guid("0418D949-A8DF-4592-B345-BF0962308545")]
    public interface Region{
        int koreanLunisolar(int year, int month, int day);
    }

    [ClassInterface(ClassInterfaceType.None)]
    [Guid("FC9020B0-2537-4C16-8003-39356E736259")]
    public class ConvertTo : Region
    {

        public int koreanLunisolar(int year, int month, int day)
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

        private String convertTo(int year, int month, int day) {
            //DateTime temp = new DateTime();
            String date = year.ToString();
            date += "-" + (month < 10 ? "0" + month.ToString() : month.ToString());
            date += "-" + (day < 10 ? "0" + day.ToString() : day.ToString());
            //date += " " + (temp.get)
            return date;
        }
    }
}
