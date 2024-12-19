
// // Implementation of non-const [] operator. This function
// // must return a reference as array element can be put on
// // the left side
// int& Array::operator[](int index)
// {
//     if (index >= size) {
//         cout << "Array index out of bound, exiting";
//         exit(0);
//     }
//     return ptr[index];
// }

// /*
// Array *arr;
// const arr[1] != 123
// nonconst arr[1] = 123
// */