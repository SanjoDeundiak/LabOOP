using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Person : ICloneable
    {
        public string name { set; get; }
        public string surname { set; get; }
        public System.DateTime birthday { set; get; }

        public Person() { }

        public Person(string name, string surname, System.DateTime birthday)
        {
            if (name == null || surname == null)
                throw new ArgumentNullException();
            this.name = name;
            this.surname = surname;
            this.birthday = birthday;
        }

        public Person(Person other)
        {
            name = other.name;
            surname = other.surname;
            birthday = other.birthday;
        }

        public object Clone()
        {
            return MemberwiseClone();
        }

        public override bool Equals(object otherObj)
        {
            if (otherObj == null)
                return false;

            if (!(otherObj is Person))
                return false;

            Person other = otherObj as Person;
            return (name == other.name && surname == other.surname && birthday == other.birthday);
        }

        public static bool operator ==(Person p1, Person p2)
        {
            return p1.Equals(p2);
        }

        public static bool operator !=(Person p1, Person p2)
        {
            return !(p1 == p2);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = (int)2166136261;

                hash = hash * 16777619 + name.GetHashCode();
                hash = hash * 16777619 + surname.GetHashCode();
                hash = hash * 16777619 + birthday.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return name + "\t" + surname + "\t" + birthday.ToShortDateString();
        }

        public string Brief()
        {
            return name;
        }

        static void Main(string[] args)
        {
            Person p1 = new Person("Sanjo", "Deundiak", new System.DateTime(1995, 1, 20));
            System.Console.WriteLine(p1.ToString());
            System.Console.WriteLine(p1.Brief());
            System.Console.ReadKey();
        }
    }
}
