#include <iostream>
#include <vector>
using namespace std;

// O(nLog(n) + mLog(m)) time | O(1) space
vector<int> smallestDifferenceMyWay(vector<int> &arrayOne, vector<int> &arrayTwo) {
    sort(arrayOne.begin(), arrayOne.end());// O(nLog(n)) time
    sort(arrayTwo.begin(), arrayTwo.end());// O(mLog(m)) time
    int smallestDifferenceFoundSoFar = INT16_MAX;// O(1) space
    int arrayOneElement = 0;// O(1) space
    int arrayTwoElement = 0;// O(1) space
    int arrayOnePointer = 0;// O(1) space
    int arrayTwoPointer = 0;// O(1) space
    while((arrayOnePointer < arrayOne.size()) && (arrayTwoPointer < arrayTwo.size())) {// O(n + m) time
        int currentAbsoluteDifference = abs(arrayOne[arrayOnePointer] - arrayTwo[arrayTwoPointer]);// O(1) time
        if(currentAbsoluteDifference < smallestDifferenceFoundSoFar) {// O(1) time
            smallestDifferenceFoundSoFar = currentAbsoluteDifference;// O(1) time | O(1) space
            arrayOneElement = arrayOne[arrayOnePointer];// O(1) time | O(1) space
            arrayTwoElement = arrayTwo[arrayTwoPointer];// O(1) time | O(1) space
        }
        if(arrayOne[arrayOnePointer] < arrayTwo[arrayTwoPointer]) {// O(1) time
            arrayOnePointer++;// O(1) time | O(1) space
        } else if(arrayTwo[arrayTwoPointer] < arrayOne[arrayOnePointer]) {// O(1) time
            arrayTwoPointer++;// O(1) time | O(1) space
        } else {// O(1) time
            break;
        }
    }
    return vector<int> {arrayOneElement, arrayTwoElement};// O(1) time | O(1) space
}

// O(nLog(n) + mLog(m)) time | O(1) space
vector<int> smallestDifferenceArray(vector<int> &arrayOne, vector<int> &arrayTwo) {
    sort(arrayOne.begin(), arrayOne.end());// O(nLog(n)) time
    sort(arrayTwo.begin(), arrayTwo.end());// O(mLog(m)) time
    int indexOne = 0;// O(1) space
    int indexTwo = 0;// O(1) space
    int smallest = INT16_MAX;// O(1) space
    int current = INT16_MAX;// O(1) space
    vector<int> smallestPair;// O(1) space
    while((indexOne < arrayOne.size()) && (indexTwo < arrayTwo.size())) {// O(n + m) time
        int firstNumber = arrayOne[indexOne];// O(1) space
        int secondNumber = arrayTwo[indexTwo];// O(1) space
        if(firstNumber < secondNumber) {// O(1) time
            current = secondNumber - firstNumber;// O(1) time | O(1) space
            indexOne++;// O(1) space
        } else if(secondNumber < firstNumber) {// O(1) time
            current = firstNumber - secondNumber;// O(1) time | O(1) space
            indexTwo++;// O(1) space
        } else {// O(1) time
            return vector<int> {firstNumber, secondNumber};// O(1) time | O(1) space
        }
        if(smallest > current) {// O(1) time
            smallest = current;// O(1) time | O(1) space
            smallestPair = {firstNumber, secondNumber};// O(1) time | O(1) space
        }
    }
    return smallestPair;// O(1) time
}

int main() {
    vector<int> arrayOne = {-1, 5, 10, 20, 28, 3};
    vector<int> arrayTwo = {26, 134, 135, 15, 17};
    vector<int> resultOne = smallestDifferenceMyWay(arrayOne, arrayTwo);
    vector<int> resultTwo = smallestDifferenceArray(arrayOne, arrayTwo);
    for(int element : resultOne) {
        cout << element << " ";
    }
    cout << endl;
    for(int element : resultTwo) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
