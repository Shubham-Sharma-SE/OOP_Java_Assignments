import random

trials = 100000

count_six = 0
count_greater_than_3 = 0
count_even_given_greater_than_3 = 0

for _ in range(trials):
    roll = random.randint(1, 6)


    if roll == 6:
        count_six += 1

    
    if roll > 3:
        count_greater_than_3 += 1
        if roll % 2 == 0:
            count_even_given_greater_than_3 += 1

sim_simple = count_six / trials
theory_simple = 1 / 6

sim_conditional = count_even_given_greater_than_3 / count_greater_than_3
theory_conditional = 2 / 3

print("===== Dice Rolling =====")
print("Simulated P(Roll = 6):", sim_simple)
print("Theoretical P(Roll = 6):", theory_simple)

print("\nSimulated P(Even | Roll > 3):", sim_conditional)
print("Theoretical P(Even | Roll > 3):", theory_conditional)

print("\nInterpretation:")
print("The simulated probabilities are very close to the theoretical probabilities.")