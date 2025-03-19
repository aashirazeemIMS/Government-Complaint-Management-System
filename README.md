**Government Complaint Management System**

**1. Introduction**
The **Government Complaint Management System** is a **C++ console-based application** that allows citizens to register complaints and enables government officials to manage them. This system ensures **transparency** and **efficiency** in handling public grievances.

**2. Objectives**
- Enable citizens to **submit complaints** regarding government services.
- Provide a **secure** user authentication mechanism.
- Allow officials to **manage and update** complaint statuses.
- Store and retrieve complaints using **file handling**.
- Utilize **pointers, structures, arrays, vectors, recursion, and function overloading**.

**3. Features**
- **User Registration & Authentication**: Users can sign up as either **citizens** or **government officials**.
- **Complaint Registration**: Citizens can submit complaints along with their **government ID** and name.
- **View Complaints**: Citizens can view their **submitted complaints** and track their status.
- **Complaint Management**: Government officials can view **all complaints** and update their status.
- **File Handling**: Data is stored in **text files** (`users.txt` and `complaints.txt`) for persistence.
- **Loops & Recursion**: Used for managing complaint searches and iterative processing.
- **Function Overloading**: Allows multiple versions of functions for enhanced usability.
- **Arrays & Vectors**: Used for efficient complaint storage and retrieval.

**4. Implementation Details**
- **Programming Language**: **C++**
- **Data Storage**: **File handling (Text Files)**
- **Security**: **Basic authentication** implemented.
- **User Interface**: **Console-based menu-driven interaction**.

**5. Code Structure**
- **Main Functions**:
  - `registerUser()`: Registers a new user.
  - `loginUser()`: **Authenticates** users based on stored credentials.
  - `registerComplaint()`: Allows citizens to **submit complaints**.
  - `viewMyComplaints()`: Displays complaints associated with a user’s **government ID**.
  - `manageComplaints()`: Enables officials to **update complaint statuses**.
  - `searchComplaint()`: Uses **recursion** to locate complaints by ID.
  - `updateComplaintStatus()`: Uses **function overloading** to update statuses with different input types.

**6. System Flowchart**
```
         Start
           |
     User Registration/Login
           |
 Citizen  ----  Official
   |              |
 Register     View Complaints
 Complaint     & Update Status
   |              |
 View My      Change Status
 Complaints   to 'Resolved'
   |              |
    --------------
          |
         End
```

**7. Enhancements & Future Scope**
- **Implement a database** (MySQL or SQLite) for better data management.
- **Introduce a GUI** for better usability.
- **Enhance security** using advanced encryption techniques.
- **Develop a web or mobile application** for broader accessibility.

**8. Testing & Validation**
- **Test Case 1**: **User registration** with an existing username should fail.
- **Test Case 2**: Logging in with **incorrect credentials** should display an error.
- **Test Case 3**: Submitting a complaint without a **valid government ID** should be restricted.
- **Test Case 4**: **Recursive search should correctly retrieve complaints by ID**.
- **Test Case 5**: **Officials should be able to update complaint status using function overloading**.

**9. Conclusion**
This project successfully demonstrates a **simple yet effective complaint management system** for government services. It integrates key C++ concepts like **pointers, structures, recursion, vectors, and file handling**, ensuring a **structured and scalable solution** for grievance management.

---

**Created by Aashir Ali - SE2**
Goodbye and thank you for reviewing my project!

