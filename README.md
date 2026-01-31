# Bank Project 🏦

A C++ banking management system implementing role-based permissions, a login system, and file-based data storage. This project focuses on clean architecture, separation of concerns, and simple persistent storage without a database.

---

## 📌 Table of Contents
- [Project Description](#project-description)
- [Key Features](#key-features)
- [What I Learned](#what-i-learned)
- [Technologies Used](#technologies-used)
- [Purpose](#purpose)  
- [Updates](#updates)
- [Screenshots](#screenshots)
---

## Project Description
This project demonstrates a compact bank management application written in C++ with the following core concepts:

- Role-based permission system (authorization) that controls what actions different users may perform.
- Login system that authenticates users and grants or denies access based on their permissions.
- File-based storage for clients, users, and transaction data (no external database required).
- Separation of concerns in the codebase to keep authentication, business logic, and data access modular and maintainable.
- User interfaces (console or simple GUI) that let authorized users manage clients, perform transactions, and maintain system users.

---

## Key Features
- Add, search, and remove clients
- Perform account operations (deposit, withdraw, view balance/total)
- Manage application users (create, edit, delete, search)
- Permission checks that prevent unauthorized actions

---

## What I Learned
- Implementing role-based authorization and access control
- Designing and building a login/authentication flow
- Writing clean, modular, and readable C++ code
- Applying separation of concerns and organizing code for maintainability
- Handling file I/O for persistent storage without a database
- Designing simple user management and transaction workflows

---

## Technologies Used
- Programming language: C++
- Build tools: Standard C++ toolchain (`g++`, `clang++`, or equivalent)
- Version control: Git & GitHub
- Data storage: File-based storage (text or structured files)
- Standard libraries: `<fstream>`, `<iostream>`, `<vector>`, `<string>`, etc.

---

## Purpose
This project was created for learning and practice. It is intended to:

- Develop a deeper understanding of authorization, authentication, and application structure.
- Provide a hands-on exercise in organizing a C++ project with clear responsibilities.
- Serve as a starting point for extending to more advanced storage (e.g., databases) or a GUI in the future.

*Note: This implementation is for educational purposes and not intended as a production-grade banking system.*  

---

## Updates


The project is currently being refactored and enhanced with the following updates:

1. **Conversion to OOP (Object-Oriented Programming)**
   - The code is being reorganized into classes and objects.
   - Responsibilities are separated into modules for better maintainability.
   - Example: `Client`, `User`, `Transaction`, and `BankSystem` classes are being implemented.

2. **Library Integration**
   - External libraries can now be easily included in the project.
   - **Steps to add a library in Visual Studio:**
     1. Open **Solution Explorer** and right-click on your project.
     2. Select **Properties**.
     3. Go to **Configuration Properties** > **C/C++** > **General**.
        - Add the path to library headers in **Additional Include Directories**.
     4. Go to **Configuration Properties** > **Linker** > **General**.
        - Add the path to library files (`.lib`) in **Additional Library Directories**.
     5. Click **OK** and rebuild the project.

> These changes aim to make the project more modular, maintainable, and ready for future extensions, such as adding new features, external libraries, or GUI improvements.

---

## Screenshots
### Login Screen:   
This image shows the login screen, where hints are provided for each user to enter the username and password displayed on the screen.  

<img width="1483" height="762" alt="login" src="https://github.com/user-attachments/assets/268dff01-be0f-4bb1-91a4-2c0281eef897" />

--- 
### Main Screen:      
This screen displays all clients and allows adding, deleting, or searching for clients easily.

<img width="1483" height="762" alt="menue" src="https://github.com/user-attachments/assets/1b5de676-0e33-4fd3-95a7-a5efe35112cb" />   

---
### Operations Screen:   
This screen allows the user to perform financial operations such as adding balance, withdrawing balance, and checking the total.

<img width="1483" height="762" alt="transaction" src="https://github.com/user-attachments/assets/77cae0d6-cd18-4956-9da9-9fa8729dfcce" />

---   
### User Management Screen:   
This screen is used to manage system user access, allowing the addition of new users, deletion, editing of their information, or searching for any user.

<img width="1483" height="762" alt="manage" src="https://github.com/user-attachments/assets/bf175d01-1dd5-401e-8f76-2f5c6b5b89cb" />

---
### Permissions Screen:   
If the user has permission to access the system, they are allowed in; if not, this screen appears to inform them that access is denied.

<img width="1483" height="762" alt="premission" src="https://github.com/user-attachments/assets/02c2b3a7-218f-4d1f-a963-e71e1d951a9d" />

---

<p align="left">
  <strong> Developed by  Loay Anwar</strong> <br>
   <a href="https://github.com/LoayCpp">
    <img width="50" height="50" alt="Loay-modified" src="https://github.com/user-attachments/assets/8fee5f57-fc06-4723-a7ad-2d077ab1d7e2" />
</a>

  <a href="https://www.linkedin.com/in/loay-anwar-alarify-259634260" target="_blank">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" />
  </a>
  <a href="https://www.facebook.com/share/1ByuvJEiyu/" target="_blank">
    <img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white" alt="Facebook" />
  </a>
  <a href="https://www.instagram.com/7.loa7?igsh=cWxjeHRzM2pnaWc2" target="_blank">
    <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram" />
  </a>
   <a href="https://t.me/Loay_Anwar" target="_blank">
    <img src="https://img.shields.io/badge/Telegram-26A5E4?style=for-the-badge&logo=telegram&logoColor=white" alt="Telegram" />
  </a>
    <a href="https://wa.me/967733693579" target="_blank">
    <img src="https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white" alt="WhatsApp" />
  </a>
</p>
