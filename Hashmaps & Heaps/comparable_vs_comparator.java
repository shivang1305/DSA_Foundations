/*  */

import java.io.*;
import java.util.*;

public class Main {
    
    public static class Student implements Comparable<Student>{
        int rno, marks, age;
        
        Student(int rno, int marks, int age) {
            this.rno = rno;
            this.marks = marks;
            this.age = age;
        }
        
        public int compareTo(Student obj) {
            return this.rno - obj.rno; // to sort the objects of the students by roll number in ascending order
            // return obj.rno - this.rno -> for decending order
        }
        
        public String toString() { // to display the object of the student
            return "Roll No: " + this.rno + " Marks: " + this.marks + " Age: " + this.age;
        }
    }

    public static void main(String[] args) throws Exception {
        int[] arr = {10, 2, 17, 3, 18, 9, 22};
        PriorityQueue<Student> pq = new PriorityQueue<>(); // calling the parameterized constructor
        
        pq.add(new Student(12, 85, 19));
        pq.add(new Student(10, 80, 20));
        pq.add(new Student(1, 45, 19));
        pq.add(new Student(5, 69, 21));
        pq.add(new Student(16, 35, 22));
        pq.add(new Student(29, 55, 18));
        
        while(pq.size() > 0) 
            System.out.println(pq.remove());
    }
}