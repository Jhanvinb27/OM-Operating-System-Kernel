# OM Operating System Kernel

The **OM Operating System Kernel** is a lightweight educational operating system kernel developed to understand the internals of OS design. 
This project explores concepts such as process management, memory management, file systems, and low-level hardware interaction.

---

## 📌 Features

- **Bootloader** – Initializes the system and loads the kernel into memory  
- **Kernel Core** – Handles process scheduling, interrupts, and system calls  
- **Memory Management** – Basic paging/segmentation implementation  
- **File System (Unix-like)** – Simplified file management and storage interface  
- **Device Drivers** – Support for basic I/O devices  

---

## 🛠️ Project Structure

OM Operating System Kernel/
│── boot/ # Bootloader source code
│── kernel/ # Core kernel functionality
│── memory/ # Memory management modules
│── fs/ # File system implementation
│── drivers/ # Device drivers
│── include/ # Header files
│── tests/ # Unit and integration tests
│── docs/ # Documentation

---

## 🚀 Getting Started

### Prerequisites
- **GCC cross-compiler** (x86 or ARM depending on target)  
- **QEMU** (for virtualization and testing)  
- **Make** (for build automation)  

### Build & Run

```bash
# Clone the repository
git clone https://github.com/Jhanvinb27/OM-Operating-System-Kernel.git
cd "OM Operating System Kernel"

# Build the kernel
make

# Run using QEMU
qemu-system-x86_64 -kernel build/kernel.bin
