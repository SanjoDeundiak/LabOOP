using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Employee : Person, ICloneable
    {
        public System.DateTime hiredate { set; get; }
        public Position position { set; get; }

        public Employee() : base() { position = new Position();  }

        public Employee(Person person, System.DateTime hiredate, Position position) : base(person)
        {
            this.hiredate = hiredate;
            this.position = position.Clone() as Position;
        }

        public override bool Equals(object otherObj)
        {
            if (otherObj == null)
                return false;

            if (!(otherObj is Employee))
                return false;
            Employee other = otherObj as Employee;
            return Person.Equals(this, other) && hiredate == other.hiredate && position == other.position;
        }

        public static bool operator==(Employee e1, Employee e2)
        {
            return e1.Equals(e2);
        }

        public static bool operator!=(Employee e1, Employee e2)
        {
            return !e1.Equals(e2);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = (int)2166136261;

                hash = hash * 16777619 + base.GetHashCode();
                hash = hash * 16777619 + hiredate.GetHashCode();
                hash = hash * 16777619 + position.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return base.ToString() + '\t' + position.ToString() + "\t" + hiredate.ToShortDateString();
        }

        public new string Brief()
        {
            return base.ToString() + ' ' + hiredate.ToShortDateString();
        }

        static void Main(string[] args)
        {
            Employee e1 = new Employee(new Person("Sanjo", "Deundiak", new System.DateTime(1995, 1, 20)),
                new System.DateTime(2014, 8, 22), new Position("CEO", Responsibility.Manager, 5000));
            System.Console.WriteLine(e1.ToString());
            System.Console.WriteLine(e1.Brief());
            System.Console.ReadKey();
        }
    }
}
