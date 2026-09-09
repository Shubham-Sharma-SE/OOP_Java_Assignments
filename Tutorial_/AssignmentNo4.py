# Write a Python program that generates marks for 100 students using a Normal Distribution and calculates the probability associated with a user-entered marks value X

# Develop a Python program to analyze the examination marks of 100 students using the Normal Distribution. Assume that the examination 
# is conducted for 100 marks,. The program should randomly generate marks for 100 students using a Normal Distribution and ensure that all generated marks remain within the valid range of 0–100. Students must create 
# their own user-defined function to calculate 
# the Normal Distribution Probability Density Function (PDF) using the formula. The calculated probability density should be obtained for each student's marks, and a scatter plot should be created with and ,
# representing all 100 students. The program should then provide another
# user-defined function that accepts a marks value (x) from the user and calculates and displays the  P(X=x),
# P(X<x) , and the P(X>x) , with the results displayed in both decimal and percentage form. The program should also validate the user's input to ensure that (x) lies between 0 and 100.

import random
import math

student_marks = [random.gauss(50, 15) for _ in range(100)]


def pdf(x, mean, std_dev):
    exponent = math.exp(-((x - mean) ** 2) / (2 * std_dev ** 2))
    return (1 / (std_dev * math.sqrt(2 * math.pi))) * exponent

x= int(input("Enter a marks value (0-100): "))
while x < 0 or x > 100:
    print("Invalid input. Please enter a marks value between 0 and 100.")
    x = int(input("Enter a marks value (0-100): ")) 

mean = sum(student_marks) / len(student_marks)
std_dev = math.sqrt(sum((mark - mean) ** 2 for mark in student_marks) / len(student_marks))

