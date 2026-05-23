# Mess Management System — C++ Console Project

A **beginner-friendly C++ console application** for managing **university hostel mess student records**. Built as a **1st semester Bachelor's degree programming project**, this system demonstrates core concepts such as **file handling**, **CSV data storage**, **string manipulation**, **vectors**, and **menu-driven program design**.

> **Keywords:** C++ project, mess management system, student record management, hostel mess billing, console application, file I/O in C++, CSV database, university semester project, programming fundamentals.

---

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Data Format](#data-format)
- [Prerequisites](#prerequisites)
- [Installation & Setup](#installation--setup)
- [How to Run](#how-to-run)
- [Usage Guide](#usage-guide)
- [Sample Output](#sample-output)
- [Concepts Covered](#concepts-covered)
- [Visual Studio Note](#visual-studio-note)
- [Future Improvements](#future-improvements)
- [Author](#author)
- [License](#license)

---

## About the Project

The **Mess Management System** is a simple **command-line (CLI) application** written in **C++** that helps track students registered in a college or university mess (dining hall). Administrators can register students, search records, update mess attendance status (`in` / `out`), calculate monthly bills, and maintain sorted records — all stored persistently in a **CSV file**.

This project is ideal for:

- **1st semester C++ students** learning programming basics
- Students looking for a **simple file-handling project idea**
- Anyone building a **hostel / mess management system** as a college assignment
- Developers practicing **CSV read/write operations** in C++

---

## Features

| # | Feature | Description |
|---|---------|-------------|
| 1 | **Register Student** | Add a new student with registration number and name |
| 2 | **Search Record** | Find a student by registration number |
| 3 | **Update Mess Status** | Change status to `in` or `out` and track days |
| 4 | **Delete Record** | Remove a student from the database |
| 5 | **In/Out Count** | Display total students currently `in` or `out` |
| 6 | **Calculate Bill** | Compute bill as `days × 300` (PKR per day) |
| 7 | **Sort Records** | Sort all entries by registration number |
| 8 | **Exit** | Close the application |

---

## Technologies Used

- **Language:** C++ (C++11 compatible)
- **Standard Library:** `<iostream>`, `<fstream>`, `<string>`, `<sstream>`, `<vector>`
- **Storage:** CSV file (`data.csv`)
- **IDE (recommended):** Visual Studio Community / VS Code / Code::Blocks / Dev-C++

---

## Project Structure

```
Mess-management/
├── code.cpp          # Main source code (all program logic)
├── data.csv          # Student records database (CSV format)
└── README.md         # Project documentation
```

---

## Data Format

Each student record is stored as a comma-separated row in `data.csv`:

```
registration_number,name,bill,status,days
```

| Column | Type | Example | Description |
|--------|------|---------|-------------|
| `registration_number` | String | `2021001` | Unique student ID |
| `name` | String | `Ahmed Khan` | Full name |
| `bill` | Integer | `300` | Total mess bill (PKR) |
| `status` | String | `in` / `out` | Current mess attendance |
| `days` | Integer | `1` | Number of days marked `in` |

**Sample data:**

```csv
reg,name,bill,status,days
2021001,Jalees Ur Rehman,300,in,1
2021002,Majid Shah,0,out,0
2021003,Ahmed Khan,0,out,0
```

---

## Prerequisites

Before running this project, make sure you have:

- A **C++ compiler** installed:
  - [MinGW-w64](https://www.mingw-w64.org/) (Windows)
  - [GCC/G++](https://gcc.gnu.org/) (Linux / macOS)
  - [Visual Studio Community](https://visualstudio.microsoft.com/) with C++ workload (Windows)
- Basic familiarity with the **command line / terminal**

---

## Installation & Setup

### 1. Clone the repository

```bash
git clone https://github.com/danishjavedcodes/Mess-management.git
cd Mess-management
```

### 2. Compile the program

**Using g++ (Linux / macOS / MinGW):**

```bash
g++ code.cpp -o mess_management
```

**Using Visual Studio Community (Windows):**

1. Open `code.cpp` in Visual Studio
2. Create a new **Console App (C++)** project or open the file directly
3. See [Visual Studio Note](#visual-studio-note) if you encounter array size errors
4. Press **Ctrl + F5** to build and run

---

## How to Run

**Linux / macOS:**

```bash
./mess_management
```

**Windows (MinGW):**

```bash
mess_management.exe
```

> **Important:** Run the executable from the project folder so it can read and write `data.csv` in the same directory.

---

## Usage Guide

When the program starts, you will see a menu:

```
***********************************
Welcome To Mess Student Record
***********************************
Select option
 1) Register new student.
 2) Search Student record.
 3) Change Student mess status.
 4) Delete student record.
 5) Show total number of in/out students.
 6) Calculate total bill.
 7) Sort table.
 8) Exit.
```

### Register a new student

- Enter a unique **registration number** and **name**
- Default status is set to `out` with bill `0` and days `0`
- Duplicate registration numbers are rejected

### Update mess status

- Enter the student's registration number
- Change status to `in` or `out`
- Each status change to `in` increments the **days** counter by 1

### Calculate bill

- Bill formula: **`bill = days × 300`**
- Result is saved back to `data.csv`

---

## Sample Output

```
Enter registration number: 2021001
Record found
2021001,Jalees Ur Rehman,300,in,1

Total number of IN stidents are 2
Total number of OUT stidents are 14

Bill of Registration number 2021001 is 300
```

---

## Concepts Covered

This project demonstrates the following **1st semester C++ programming concepts**:

- Variables, data types, and input/output (`cin`, `cout`)
- Functions and function prototypes
- Conditional statements (`if`, `else`, `switch`)
- Loops (`for`, `while`)
- **File handling** — reading and writing with `ifstream`, `ofstream`, `fstream`
- **String processing** — `stringstream`, `getline`, character parsing
- **STL vectors** — `vector<vector<string>>` for tabular data
- **Sorting algorithm** — selection-style sort on registration numbers
- **CSV file** as a simple flat-file database
- Menu-driven program architecture

---

## Visual Studio Note

If you open this code in **Visual Studio Community** and get errors related to variable-length arrays, replace dynamic array declarations like:

```cpp
string tab[t_rows][5];
```

with a fixed-size array:

```cpp
string tab[100][5];
```

This avoids compiler issues with VLAs (Variable Length Arrays), which are not standard in C++.

---

## Future Improvements

Possible enhancements for advanced semesters:

- [ ] Add a login system for admin access
- [ ] Replace CSV with SQLite or MySQL database
- [ ] Build a **GUI** using Qt or a web frontend
- [ ] Add input validation and error handling
- [ ] Export reports to PDF
- [ ] Add monthly billing history
- [ ] Implement a continuous menu loop until exit

---

## Author

**Danish Javed**

- GitHub: [@danishjavedcodes](https://github.com/danishjavedcodes)
- Repository: [Mess-management](https://github.com/danishjavedcodes/Mess-management)

---

## License

This project is open source and available for **educational purposes**. Feel free to use, modify, and learn from it for your own **C++ semester projects**.

---

<p align="center">
  <b>C++ Mess Management System</b> · Student Record Management · Hostel Billing · 1st Semester Project
</p>
