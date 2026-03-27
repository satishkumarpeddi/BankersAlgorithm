🚀 Banker's Algorithm & Deadlock Prevention (C)

A complete implementation of the Banker’s Algorithm with enhanced deadlock detection and prevention techniques using the C programming language.

This project simulates real-world resource allocation in operating systems, ensuring safe execution of processes while avoiding and recovering from deadlocks.

📌 Overview

The Banker’s Algorithm, introduced by Edsger W. Dijkstra, is a resource allocation and deadlock avoidance algorithm that tests for system safety before granting resource requests.

This project goes a step further by:

Detecting unsafe states (deadlocks)
Applying deadlock prevention strategies
Dynamically reallocating resources
Driving the system back to a safe state
⚙️ Features

✅ Input-driven simulation (Processes & Resources)
✅ Computes:

Max Matrix
Allocation Matrix
Need Matrix
Available Resources

✅ Deadlock detection
✅ Deadlock prevention using:

✔ Eliminating Hold & Wait
✔ Applying Preemption

✅ Step-by-step execution tracing
✅ Final safe resource state output

🧠 Core Concepts Covered
Deadlock & Unsafe States
Resource Allocation
Process Synchronization
Banker’s Safety Algorithm
Deadlock Prevention vs Avoidance
📂 Project Structure
BankersAlgorithm/
│
├── BankersDeadLockPrevention.c   # Main implementation
├── BankersLockAvoidance.c       # (Optional) Avoidance logic
└── README.md                    # Documentation
🛠️ How It Works
User inputs:
Number of processes (P)
Number of resources (R)
Max matrix
Allocation matrix
Available resources
System computes:
Need = Max - Allocation
Safety Check:
Determines whether processes can execute safely
If unsafe:
Applies prevention:
Preemption (reclaim resources)
Eliminates hold-and-wait
Re-evaluates until:
Safe execution is possible OR
No further improvement possible
▶️ Sample Execution
Enter number of processes: 3
Enter number of resources: 3

Max Matrix:
7 5 3
3 2 2
9 0 2

Allocation Matrix:
0 1 0
2 0 0
3 0 2

Available:
3 3 2

Deadlock detected!
Applying prevention...

Final Available Resources:
10 4 4
🧩 Algorithm (Simplified)
Calculate Need matrix
Check if any process can execute
If yes:
Release its resources
If no:
Apply preemption
Repeat until all processes finish or deadlock persists
💻 Compilation & Execution
gcc BankersDeadLockPrevention.c -o banker
./banker
📈 Output Explanation
Safe State → All processes executed successfully
Unsafe State → Deadlock detected
Prevention Applied → Resources reallocated dynamically
🔥 Why This Project Stands Out

Unlike basic implementations, this project:

✔ Combines Detection + Prevention
✔ Simulates real OS-level decision making
✔ Demonstrates dynamic recovery from deadlocks
✔ Provides clear execution tracing

🎯 Use Cases
Operating Systems Lab Projects
Interview Preparation (System Design / OS)
Understanding Resource Allocation
Academic Demonstrations
🤝 Contributing

Contributions are welcome!

Feel free to:

Improve optimization
Add GUI/visualization
Extend to distributed systems
📜 License

This project is open-source and available under the MIT License.

🙌 Acknowledgements
Operating System concepts
Banker’s Algorithm theory
Academic OS lab implementations
