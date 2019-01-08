# Задачи

#### Задача 0

Да се намери сумата на двоично дърво от int, като на първо, трето, пето, и т.н. ниво се елементите се сумира, а на 2ро, 4то, 6то, и т.н. ниво, елементите се умножават.

Пример:

    1
    
   / &nbsp;  \      -> ниво 1 => +
   
  5   6
  
 / \   \    -> ниво 2 => *
 
8   2   3

Резултат: 8 * 2 * 5 + 1 + 6 * 3


#### Задача 1


Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words.

Ex.:

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

**Input** :  ilike
**Output** : Yes 
The string can be segmented as "i like".

**Input** :  ilikesamsung
**Output** : Yes
The string can be segmented as "i like samsung" or 
"i like sam sung".
