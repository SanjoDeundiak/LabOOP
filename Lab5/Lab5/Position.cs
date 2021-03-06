﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    enum Responsibility
    {
        None,
        Worker,
        Manager,
        Employer
    };

    class Position : ICloneable, IComparable
    {
        public string title { set; get; }
        public Responsibility responsibility {set; get; }
        public float salary { set; get; }

        public Position() { salary = 0; responsibility = Responsibility.None; }

        public Position(string title, Responsibility responsibility, float salary)
        {
            if (title == null)
                throw new ArgumentNullException();
            this.title = title;
            this.responsibility = responsibility;
            this.salary = salary;
        }

        public object Clone()
        {
            return MemberwiseClone();
        }

        public override bool Equals(object otherObj)
        {
            if (otherObj == null)
                return false;

            if (!(otherObj is Position))
                return false;

            Position other = otherObj as Position;
            return (title == other.title && responsibility == other.responsibility && salary == other.salary);
        }

        public static bool operator==(Position p1, Position p2)
        {
            return p1.Equals(p2);
        }

        public static bool operator!=(Position p1, Position p2)
        {
            return !(p1 == p2);
        }

        public static Position operator +(Position p1, float a)
        {
            if (p1 == null)
                throw new ArgumentNullException();

            p1.salary += a;
            return p1;
        }

        public int CompareTo(object other)
        {
            if (other == null)
                throw new ArgumentNullException();

            if (!(other is Position))
                throw new ArgumentException();

            if (salary - ((Position)other).salary < 0)
                return -1;
            if (salary - ((Position)other).salary > 0)
                return 1;

            return 0;
        }

        public static bool operator>(Position p1, Position p2)
        {
            return (p1.responsibility == p2.responsibility && p1.salary > p2.salary);
        }

        public static bool operator<(Position p1, Position p2)
        {
            return (p1.responsibility == p2.responsibility && p1.salary < p2.salary);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = (int)2166136261;

                hash = hash * 16777619 + title.GetHashCode();
                hash = hash * 16777619 + responsibility.GetHashCode();
                hash = hash * 16777619 + salary.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            string res = title + "\t";

            switch (responsibility)
            {
                case Responsibility.None:       res += "None"; break;
                case Responsibility.Worker:     res += "Worker"; break;
                case Responsibility.Manager:    res += "Manager"; break;
                case Responsibility.Employer:   res += "Employer"; break;
            }
            res += "\tSalary: " + Convert.ToString(salary);
            return res;
        }

        static void Main(string[] args)
        {
            Position p1 = new Position("Head officer", Responsibility.Manager, 1500);
            Position p2 = new Position("Assistant", Responsibility.Worker, 500);
            Position p3 = p2.Clone() as Position;
            Position p4 = p2;
            Position p5 = new Position("Executive officer", Responsibility.Manager, 1200);
            System.Console.Write(p1.ToString() + "\n" + p2.ToString() + "\n" + p3.ToString() + "\n" + p4.ToString() + "\n\n");

            System.Console.Write(p1 == p2); System.Console.Write(" ");
            System.Console.Write(p2 == p3); System.Console.Write(" ");
            System.Console.Write(p2 == p4); System.Console.Write(" ");

            System.Console.Write("\n");
            System.Console.Write(p5 < p1); System.Console.Write("\n");
            p1 += p5.salary;
            System.Console.Write(p1.ToString() + "\n");

            System.Console.ReadKey();
        }
    }
}
