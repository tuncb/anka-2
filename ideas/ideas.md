# Anka 2 ideas and examples

## Features coming from anka 1

###  Rank polymorphism

```
add[1 2]
>>3
add[(1 2 3) (1 2 3)]
>>(2 4 6)
add[10 (1 2 3)]
>>(11 12 13)
```

### Function composition

```
sum mul[_1 _1] ioata inc 4
>> 55
```

### Trains

```
mul |inc dec| 5
>> 24
```

### Point free programming

```
avg: {div |sum length|}
avg (1.1 2.2 3.3)
>> 2.2
```

## Variable declarations

```
a: (1 2 3) # array of integers
b: (1.0 2.0 3.0) # array of doubles
c: ((1.0 2.0) (3.0 4.0) (5.0 6.0)) # 3x2 (3 rows, 2 columns) of doubles

d1: <f64>(1 2 3) # array of doubles, integers are auto converted
d2: <f64, 3, 1>(1 2 3) # array of doubles, 3x1, integers are auto converted
d3: <f64, 1, _>(1 2 3) # array of doubles, 1x3, integers are auto converted, number of columns are auto calculated


a: 10
a: <f32>10
a: <f32>10
```

## function definitions

```
# point free generic method
# will work with any input that can be connected to {sum 2}
# auto yields
add2: {sum 2}

# function with explicit type definition
sumsincos: [val1 <f64>, val2 <f64>] => f64 {sum {sin val1} {cos val2} }

# working auto type conversions
sumsincos [10.0 5.0]
sumsincos [10 5.0]
sumsincos [10f 5.0]

sumsincos [true 5.0] # does not work as there is no bool to double conversion
sumsincos [(10 20 30) (40 50 60)] #ok all integers are converted
```

## auto move

```
a: 10
b: 20
c: sumsincos [a b]
d: sum a c # error a is auto consumed

a: 10
b: 20
c: sumsincos [a &b]
d: sum [a c] # error a is auto consumed
d: sum [b c] # ok b was copied and saved

a: sumsincos [10 20] # ok temp values are handled automatically
```

## modules and namespaces

Each file acts as a module, everything is public unless it is explicitly defined private

```
import 'external_funcs'

# external_funs.anka
external.add2: {sum 2} # part of the external namespace
private external.add3: {sum 3} # only accessible inside the current file
```

## scope

There are no global functions, execution starts from the function called main

```
main: {print "hello world!"}
```

Function scope variables are only accessible from the function

```
sumsincos: [val1 <f64>, val2 <f64>] => f64 {
  a: sin val1 # not visible to outside
  b: sin val2 # not visible to outside

  sum a b
}
```
