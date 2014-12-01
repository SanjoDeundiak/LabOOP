using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Lab5
{
    class Organization : ICloneable
    {
        private ArrayList employees;
        public string name { set; get; }
        public int size
        {
            get { return employees.Count; }
        }

        public Organization() { employees = new ArrayList(); }

        private Organization(ArrayList employees, string name)
        {
            this.name = name;
            foreach (Employee employee in employees)
                this.employees.Add(employee);
        }

        public Organization(string name)
        {
            if (name == null)
                throw new ArgumentNullException();
            this.name = name;
            employees = new ArrayList();
        }

        public void AddEmployee(Employee employee)
        {
            if (employee == null)
                throw new ArgumentNullException();

            employees.Add(employee.Clone());
        }

        public object Clone()
        {
            return new Organization(employees, name);
        }

        public override bool Equals(object otherObj)
        {
            if (otherObj == null)
                return false;

            if (!(otherObj is Organization))
                return false;

            Organization other = otherObj as Organization;
            if (name != other.name)
                return false;

            if (employees.Count != other.employees.Count)
                return false;

            for (int i = 0; i < employees.Count; i++)
                if (!employees[i].Equals(other.employees[i]))
                    return false;

            return true;
        }

        public static bool operator ==(Organization p1, Organization p2)
        {
            return p1.Equals(p2);
        }

        public static bool operator !=(Organization p1, Organization p2)
        {
            return !(p1 == p2);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = (int)2166136261;

                hash = hash * 16777619 + employees.GetHashCode();
                hash = hash * 16777619 + name.GetHashCode();

                return hash;
            }
        }

        public string Brief()
        {
            return name;
        }

        public override string ToString()
        {
            string res = name + '\n';
            foreach (Employee employee in employees)
                res += employee.ToString() + '\n';
            return res;
        }

        public Employee this[int i]
        {
            get
            {
                return employees[i] as Employee;
            }
            set
            {
                employees[i] = value;
            }
        }
    }
}
