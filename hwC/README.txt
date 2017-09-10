    This program has three basic polynomial arithmetic funtions, add, sub, and 
multiply.We first read two polynomails from two .txt file, and first output these 
two polynomails.These two polynomails is stored as struct type, which has two 
varibles, coefficient and exponent. 

    First, we add these two polynomails and store the answer into a linked list.
Function Polyadd compelete this step. Second, we sub these two polynomails and 
store the answer into a linked list. Function Polysub complete this step, this 
function like Polyadd ,but the polynomial_2's coefficient become negative, and
we add these two. Finally, we multiply these two polynomials, this step we use
Polymul to compelete, but this function is more different than previous two functions.
This function first use two loop to run polynomial_1 and polynomial_2, and store
the answer to a linked list named C. Everytime the answer should run the C to
check whether has same exponent. If has then add, or insert to C.
