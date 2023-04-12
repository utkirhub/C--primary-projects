using System;
using System.Security.Cryptography.X509Certificates;

namespace World;
class Mono
{
    static void Main(string[] args)
    {
        int x = 9;
        int y = 0;
        Console.WriteLine("Salom Son Topish O'yiniga Xush Kelibsiz!\n");
        Console.WriteLine("Men Bir Son O'yladim Siz Uni Topishga Xarakat Qilib Ko'ring!");
        while (y != x)
        {
            Console.Write("\nSon Kiriting: ");
            int z = Convert.ToInt32(Console.ReadLine());
            if (z > x)
            {
                Console.WriteLine("\nYo'q Men O'ylagan Son" + " " + z + " Sonidan Kichkina 👇");
                Console.WriteLine("Qayta Urinib Ko'ring! ✌");
            }
            else if (z < x)
            {
                Console.WriteLine("\nYo'q Men O'ylagan Son" + " " + z + " Sonidan Katta 👆");
                Console.WriteLine("Qayta Urinib Ko'ring! ✌");
            }
            else
            {
                Console.WriteLine("\nTopdingiz Tabriklayman 👏 Men" + " " + x + " " + "Sonni O'ylagan Edim 🙂");
                break;
            }
        }
    }
}

