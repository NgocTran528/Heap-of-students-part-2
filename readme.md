``` mermaid
classDiagram
direction TB
    class Address {
        # string street
        # string city
        # string state
        # string zip
        + Address()
        + void init(street, city, state, zip)
        + void printAddress()
    }

    class Date {
        # string dateString
        # int month
        # int day
        # int month
        # int year
        + Date()
        + void init(dateString)
        + void printDate()
    }

    class Student {
        # string studentString
        # string firstName
        # string lastName
        # Date* dob
        # Date* expectedGrad
        # Address* address
        # int creditHours
        + Student()
        + ~Student()
        + void init(studentString)
        + void printStudent()
        + string getFirstName()
        + string getLastName()
        + int getCreditHours()
        + string getLastFirst()
    }

    Address --o Student
    Date --o Student
```

## Algorithms

### Address:init
```
void init(string street, string city, string state, string zip)
    copy each parameter into the matching data member
```

### Address::printAddress
```
void printAddress()
    print street then a new line
    print city, space, state, comma, space, zip, then a new line
```

### Date::init
```
void init(string dateString)
    save dateString in the data member
    make a stringstream called ss and put dateString in it
    make temporary strings monthStr, dayStr, yearStr
    getline from ss up to '/'into monthStr
    getline from ss up to '/' into dayStr
    getline from ss to the end into yearStr
    use a converter stringstream to turn each one into an int
    store them in month, day, year
```

### Address::printAddress
```
void printAddress()
    print street then a new line
    print city, space, state, comma, space, zip, then a new line
```

### Date::printDate
```
void  printDate()
    make an array of the 12 month names
    print the month name at month -1, space, day, comma, space, year
    print a new line
```

### Student::Student
```
Student()
    make a new Date on the heap for dob
    make a new Date on the heap for expectedGrad
    make a new Address on the heap for address
    set creditHours to 0
```

### Student::~Student
```
~Student()
    delete dob
    delete expectedGrad
    delete address
```

### Student::init
```
void init(string studentString)
    save studentString in the data member
    make a stringstream called splitter and put studentString in it
    getline up to ',' into firstName
    getline up to ',' into lastName
    getline up to ',' into street, city, state, zip
    getine up to ',' into dobStr, gradStr
    getline to the end into creditStr
    call address->init with dobStr
    call expectedGrad-> init with gradStr
    use a converter stringstream to turn creditStr into creditHours
```

### Student::printStudent
```
void printStudent()
    print firstName, space, lastName, new line
    call address->printAddress
    print "DOB: " then call dob->printDate
    print "Grad: " then call expectedGrad->printDate
    print "Credits: " and creditHours, new line
    print a line of underscores
```

### Student::getLastFirst
```
string getLastFirst()
    return lastName + ", " + firstName
```

## Part 2

### loadStudents
```
void loadStudents(vectorStudent*>& students)
    make an ifstream and open student.csv
    make a string called line
    while getline can read a line from the file into line
        make a new student on heap
        call its init with line
        push the pointer onto the back of the vector
    close the file
```

### showStudentNames
```
void showStudentNames(vector<Student*>&students)
    for each student in vector
        print student->getLastFirst() and a new line
```

### printStudents
```
void printStudents(vector<Student*>&students)
    for each student in the vector
        call student->printStudent()
```

### findStudent
```
void findStudent(vector<Student*>& students)
    print "last name of student: "
    read a string called target from the user
    for each student in the vector
        if student->getLastName().find(target) is not string::npos
            call student->printStudent()
```

### delStudents
```
void delStudents(vector<Student*>& students)
    for each student in the vector
        delete that student
```

### menu
```
string menu()
    print the four choices 0 to 3
    print "please choose 0-3"
    read a string called choice from the user
    return choice
```

### main
```
int main()
    make a vector of Student pointers called students
    call loadStudents with students
    make a string called choice and set it to ""
    while choice is not "0"
        choice = menu()
        if choice is "1" call showStudentNames
        else if choice is "2" call printStudents
        else if choice is "3" call findStudents
        else if choice is "0" print "bye"
        else print "not a valid choice"
    call delStudents with students
    return 0
```




