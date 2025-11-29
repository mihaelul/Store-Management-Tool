
# Rock Store Management System

A C++ project for managing employees, products, and customer orders in a rock-themed shop. Includes multithreaded order processing, dynamic validation, and automatic report generation.

##  Features

* Manage employees & products (add, edit, delete, list)
* Validate store constraints (min. staff, stock thresholds)
* Process orders from text files
* Parallel order execution using threads
* Auto-generate CSV reports (top employees by orders, revenue, salary)

---

##  Core Structure

###  Employees

Class hierarchy:
**Employee → Manager / Operator / Sales Assistant**

* Operators track active orders, total orders, and generated revenue
* Overridden methods: `afisare()`, `calculSalariu()`, destructor

###  Products

Class hierarchy:
**Product → Clothing (AV) / Disc → Vintage Disc (DV)**

* Base price + additional fees = total price
* Double-check search (name or ID), useful for typos like *“Lsnt Skeleton”*

###  Orders

* Stores product name, ID, type, quantity, album (if applicable)
* Managed through a helper class that validates and routes orders

---

##  How Order Processing Works

* Orders are read from a text file
* Each passes a series of checks: stock, limits, value cap, operator availability
* Valid orders are assigned to operators
* Each order is processed in **30s** via a dedicated thread
* If all operators are busy, the system waits and retries
* Results get stored for reporting

---

##  Reporting

Creates a CSV with the **top 3 employees** by:

* Number of processed orders
* Revenue generated
* Salary

---

##  Test Coverage

Includes scenarios for:

* Missing product
* Stock limits exceeded
* Wrong product name but correct ID
* Orders over allowed value
* Product category caps

---


---

If you want, I can also create:
✨ A stylish version with emojis & badges
📄 A Romanian version
🧱 A README with screenshots, diagrams, or examples
