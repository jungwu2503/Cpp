using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSLinkedList
{
    class Node<T>
    {
        T data;
        Node<T> next;
        public Node()
        {
            data = default(T);
            next = null;
        }
        public Node(T data)
        {
            this.data = data;
            this.next = null;
        }
        public T Data
        {
            get { return data; }
            set { data = value; }
        }
        public Node<T> Next
        {
            get { return next; }
            set { next = value; }
        }
    }
    class LinkedList<T>
    {
        Node<T> header;
        int count;
        public LinkedList()
        {
            header = null;
            count = 0;
        }
        public void addFirst(T data)
        {
            Node<T> newNode = new Node<T>(data);
            newNode.Next = header;
            header = newNode;
            count++;
        }
        public void add(T x)
        {
            Node<T> tmp = header;
            Node<T> newNode = new Node<T>(x);

            if (count == 0)
            {
                addFirst(x);
                return;
            }
            while (tmp.Next != null)
            {
                tmp = tmp.Next;
            }
            count++;
            tmp.Next = newNode;
        }
        public void remove(T x)
        {
            Node<T> tmp;
            Node<T> follow;

            tmp = header;
            follow = tmp;
            if (count == 0)
            {
                Console.WriteLine("List is empty");
                return;
            }
            if (header.Data.Equals(x))
            {
                header = header.Next;
                count--;
                return;
            }
            while (tmp != null)
            {
                if (tmp.Data.Equals(x))
                {
                    follow.Next = tmp.Next;
                    count--;
                    return;
                }
                follow = tmp;
                tmp = tmp.Next;
            }
            Console.WriteLine("Cannot find element");
        }
        public void addAt(int index, T x)
        {
            Node<T> tmp = header;
            Node<T> newNode = new Node<T>(x);

            if (index == 0)
            {
                addFirst(x);
                return;
            }
            if (index > count)
            {
                Console.WriteLine("Incorrect index");
                return;
            }
            for (int i = 0; i < index-1; i++)
            {
                tmp = tmp.Next;
            }
            newNode.Next = tmp.Next;
            tmp.Next = newNode;
            count++;
        }
        public T this[int index]  //indexer
        {
            get
            {
                Node<T> tmp = header;
                T value;

                if (count == 0)
                {
                    Console.WriteLine("List is empty");
                    Environment.Exit(-1);
                }
                if (index == 0)
                {
                    value = header.Data;
                    return value;
                }
                if (index > count - 1)
                {
                    Console.WriteLine("Incorrect index");
                    Environment.Exit(-1);
                }
                for (int i = 0; i < index; i++)
                {
                    tmp = tmp.Next;
                }
                value = tmp.Data;
                return value;
            }
            set
            {
                Node<T> tmp = header;

                if (count == 0)
                {
                    Console.WriteLine("List is empty");
                    return;
                }
                if (index > count - 1)
                {
                    Console.WriteLine("Incorrect index");
                    return;
                }
                for (int i = 0; i < index; i++)
                {
                    tmp = tmp.Next;
                }
                tmp.Data = value; // value = property
            }
        }
        public T get(int index)
        {
            Node<T> tmp = header;
            T value;

            if (count == 0)
            {
                Console.WriteLine("List is empty");
                Environment.Exit(-1);
            }
            if (index == 0)
            {
                value = header.Data;
                return value;
            }
            if (index > count-1) 
            {
                Console.WriteLine("Incorrect index");
                Environment.Exit(-1);
            }
            for (int i = 0; i < index; i++)
            {
                tmp = tmp.Next;
            }
            value = tmp.Data;
            return value;
        }
        public void set(int index, T x)
        {
            Node<T> tmp = header;

            if (count == 0)
            {
                Console.WriteLine("List is empty");
                return;
            }
            if (index > count - 1)
            {
                Console.WriteLine("Incorrect index");
                return;
            }
            for (int i = 0; i < index; i++)
            {
                tmp = tmp.Next;
            }
            tmp.Data = x;
        }
        public override string ToString()
        {
            String s;
            Node<T> tmp = header;

            s = "[";
            while (tmp != null)
            {
                s = s + tmp.Data;
                if (tmp.Next != null)
                {
                    s += ", ";
                }
                tmp = tmp.Next;
            }
            s = s + "]";

            return s;
        }

    }

    class Student
    {
        public String name;
        public int grade;
        public Student()
        {
            name = null;
            grade = 0;
        }
        public Student(String name, int grade)
        {
            this.name = name;
            this.grade = grade;
        }
        public override string ToString()
        {
            String s = name + ", " + grade + " ";
            return s;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            LinkedList<Student> xList = new LinkedList<Student>();
            xList.add(new Student("Kim", 20));
            xList.addFirst(new Student("Lee", 30));
            xList.addFirst(new Student("Park", 50));
            Console.WriteLine(xList);

            LinkedList<String> sList = new LinkedList<string>();
            sList.addFirst("Kim");
            sList.addFirst("Lee");
            sList.addFirst("Park");
            sList.addFirst("Kwon");
            Console.WriteLine(sList);

            LinkedList<int> list = new LinkedList<int>();
            list.addFirst(10);
            list.addFirst(20);
            list.addFirst(30);
            list.add(100);
            list.remove(30);
            list.addAt(3, 200);
            int p = list[2];
            Console.WriteLine(p);
            Console.WriteLine(list.get(3));
            Console.WriteLine(list);
            //list.set(3, 1000);
            list[2] = 1000;
            Console.WriteLine(list);
        }
    }
}
