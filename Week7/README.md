### Task 01 ###

# Mediancho's Unique Array Challenge

## Description
Имало едно време човек на име Медианчо и целият му професионален живот се състоял в едно: Да определя едно конкретно число B в колко нечетни по дължина подмасиви на конкретен масив се явява медиана. Медианчо обаче е бил тясно специализиран, той можел да отговаря на предния въпрос само при дадени условия:

Ако масивът му е с дължина N, то елементите на масива са между 1 и N включително и се срещат само по веднъж (Медианчо би могъл да отговори за масив [1,2,3], но не и на [1,2,2] при N = 3).

Дава ви се масив от числа, изпълняващ гореописаните условия, и Вие трябва да определите числото B в колко нечетни по дължина подмасиви се явява медиана.

## Input Format
Получавате две числа като вход: N и B, където N е големината на масива. Следват N на брой реда, които представляват съдържанието му.

## Constraints

```
1 ≤ N ≤ 10^5
1 ≤ B ≤ N
1 ≤ arr[i] ≤ N
arr[i] = arr[j] => i = j
```

## Output Format
Изведете едно число, броят на нечетните по дължина подмасиви, в които B се явява медиана.

## Sample Input 0
```
5 4
1 2 3 4 5
```

## Sample Output 0
```
2
```

## Explanation 0
2-та подмасива с нечетна дължина, за които 4 е медиана са:

```
[4]
[3, 4, 5]
```

## Sample Input 1
```
7 4
5 7 2 4 3 1 6
```

## Sample Output 1
```
4
```

## Explanation 1
4-те подмасива с нечетна дължина, за които 4 е медиана са:

```
[4]
[7, 2, 4]
[5, 7, 2, 4, 3]
[5, 7, 2, 4, 3, 1, 6]
```

***

### Task 02 ###

# Lexicographically Smallest Permutation Finder

## Description
Дадена Ви е пермутация на подредица на числата от 1 до N. Вашата задача е проста: Да намерите лексикографически най-малката пермутация на числата от 1 до N, която съдържа в себе си въпросната получена от входа пермутация като подредица.

## Input Format
Като вход получавате N и M, съответно дясната граница на числата и големината на първоначалната пермутирана подредица. Следват M реда числа num, съдържанието на въпросната подредица.

## Constraints
```
1 ≤ N ≤ 10^5
1 ≤ M ≤ N
1 ≤ num ≤ N
```

## Output Format
Изведете въпросната пермутация, разделена в whitespace-ове.

## Sample Input 0
```
5 3
1
4
2
```

## Sample Output 0
```
1 3 4 2 5
```

## Explanation 0
Като свободни числа имаме 3 и 5. "Минимизираме" и слагаме 3 между 1 и 4. Петицата е голяма, затова я слагаме най-накрая, че да има най-малко тежест. Така получаваме лексикографически минималната пермутация на числата от 1 до N = 5, която съдържа [1,4,2] като подредица.

***

### Task 03 ###

# XOR Minimum Query

## Description
В задачата ще трябва да отговорете на Q на брой заявки върху множество от числа S.

Първоначално множеството S съдържа само 1 елемент - 0 (S = {0}). При всяка заявка се въвежда едно цяло число Pi, което се добавя към множеството (S не е мултимножество ⇒ ако числото Pi вече се среща в множеството, то не трябва да бъде добавено втори път).

От вас се иска след всяка заявка да изведете по едно цяло число - минималната стойност която може да се получи чрез прилагане на xor (побитово изключващо или: ⊕) на някои 2 елемента принадлежащи на множеството.

По формално казано, след всяка заявка намерете: min({u ⊕ v|u, v ∈ S}).

## Input Format
Първият ред на стандартния вход съдържа едно цяло число Q - броя на заявките.

Следват Q на брой цели числа Pi - поредното число което трябва да бъде добавено в множеството S.

## Constraints

```
0 ≤ Q ≤ 10^5
1 ≤ Pi ≤ 10^9
```

## Output Format
Изведете Q на брой реда с по едно цяло число на всеки ред - търсената стойност за всяка от заявките.

## Sample Input 0
```
5
7
3
5
5
42
```

## Sample Output 0
```
7
3
2
2
2
```

## Explanation 0
```
S = {0} ∪ {7} = {0, 7} ⇒ минималният xor e: (0 ⊕ 7) = 7.
S = {0, 7} ∪ {3} = {0, 7, 3} ⇒ минималният xor e (0 ⊕ 3) = 3.
S = {0, 7, 3} ∪ {5} = {0, 7, 3, 5} ⇒ минималният xor e: (7 ⊕ 5) = 2.
S = {0, 7, 3, 5} ∪ {5} = {0, 7, 3, 5} ⇒ минималният xor e: (7 ⊕ 5) = 2.
S = {0, 7, 3, 5} ∪ {42} = {0, 7, 3, 5, 42} ⇒ минималният xor e: (7 ⊕ 5) = 2.
```