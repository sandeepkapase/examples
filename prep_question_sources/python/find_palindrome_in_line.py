#!/usr/bin/python
line = "This is next Level and Radar will catch it."
for word in line.split():
  if word.upper() == word.upper()[::-1]:
    print("Palindrome:", word)
