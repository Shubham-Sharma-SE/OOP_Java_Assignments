# Develop python function to manually calculate binomial probability using the binomial probability without using built in probability distribution function validate the results using skipy and visualize the probability distribution using matplotlib.
# *Consider the 10 trials with probability of success 0.6 find the probability of getting 7 success. 
# Probability of any random variable P(X:x)=nCx(p)^x(q)*n-x(1-p)
import random 
x= 7
n= 10
p= 0.6
q= 1 - p
def factorial(n):
    for i in range (1,n+1):
        factorial = n * i 



def random_probability(n,x,p):
     nCx = factorial(n)/ (factorial(x)*factorial(n-x))
     prob_random_variable = nCx * (p**x) * (q**(n-x))
     return prob_random_variable

print("The probability of getting 7 successes in 10 trials with a success probability of 0.6 is: ", random_probability(n,x,p)) 