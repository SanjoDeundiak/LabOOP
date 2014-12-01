using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    static class Test
    {
        static void Main(string[] args)
        {
            Position p1 = new Position("Head officer", Responsibility.Manager, 3000);
            
            Position p2 = p1.Clone() as Position;
            Position p3 = p1;

            System.Console.WriteLine(p1.ToString());
            System.Console.WriteLine(p2.ToString());
            System.Console.WriteLine(p3.ToString());

            p1 += 2000;

            System.Console.WriteLine(p1.ToString());
            System.Console.WriteLine(p2.ToString());
            System.Console.WriteLine(p3.ToString());

            System.Console.WriteLine(p1 == p2);
            p2 += 2000;
            System.Console.WriteLine(p1 == p2);

            Position p4 = new Position();
            p4 = p3 + 10000;
            
            Organization organization = new Organization("Microsoft");
            Person person1 = new Person("Oleksandr", "Deundiak", new System.DateTime(1995, 1, 20)),
                   person2 = new Person("Yulia", "Ptuha", new System.DateTime(1995, 7, 1)),
                   person3 = new Person("Pupkin", "Vladimir", new System.DateTime(1956, 10, 7));
            
            Position pos = new Position("Developer", Responsibility.Worker, 4000);

            organization.AddEmployee(new Employee(person1, System.DateTime.Today, pos.Clone() as Position));
            organization.AddEmployee(new Employee(person2, System.DateTime.Today, pos.Clone() as Position));
            organization.AddEmployee(new Employee(person3, System.DateTime.Today, pos.Clone() as Position));

            System.Console.WriteLine("Organization:");
            for (int i = 0; i < organization.size; i++)
                System.Console.WriteLine(organization[i].ToString());

            Person p5 = person1, p6 = organization[0];
            System.Console.WriteLine(p5.Brief());
            System.Console.WriteLine(p6.Brief());

            System.Console.WriteLine(p5.ToString());
            System.Console.WriteLine(p6.ToString());

            System.Console.ReadKey();
        }
    }
}
