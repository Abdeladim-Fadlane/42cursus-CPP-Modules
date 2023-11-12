# Ex02 : Ford Johnson Sort :

### Disclaimer: The following is a brief explanation and does not reflect the actual implementation (Check Resources Below)

<p align="center">

We Have a unsorted vector (or any container) :

<p align="center">

<img align="center" src="explanation/vector.png" width="600"/>

<p align="center">

We create a vector of pairs of unsigned integers (because the value to be inserted are positives) 

<p align="center">

<img src="explanation/vector_pair.png" width="600"/>

<p align="center">

Then we take a vector of pairs of unsigned integers and swaps the first and second elements if the first element is greater than the second element

<p align="center">

<img src="explanation/swap.gif" width="600"/>

<p align="center">

After that we take a vector of pairs of unsigned integers and extracts the second element of each pair into a new vector called the largest and the first element of each pair into a new vector called smallest.

<p align="center">

<img src="explanation/vector2.gif" width="600"/>

<p align="center">

<img src="explanation/Screen Shot 2023-03-26 at 5.56.08 PM.png" width="600"/>

<p align="center">

It’s up to you to choose which one to sort, i choose the largest and
you need to sort them use Recursively sort 

<p align="center">

Now start to insert the elements of largest to smallest by using lower_bound to get its position and the member function insert to insert.

<p align="center">

<img src="explanation/last.gif" width="600"/>