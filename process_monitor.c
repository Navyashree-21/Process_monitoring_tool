#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to display CPU usage
void displayCPUUsage() {
    printf("\n[CPU Usage Information]\n");
    system("top -bn1 | grep 'Cpu(s)'");
}

// Function to display Memory usage
void displayMemoryUsage() {
    printf("\n[Memory Usage Information]\n");
    system("free -h");
}

// Function to display running processes
void displayRunningProcesses() {
    printf("\n[Running Processes]\n");
    system("ps -eo pid,comm,pcpu,pmem --sort=-pcpu | head -15");
}

// Function to compare with Linux top command
void compareWithTop() {
    printf("\n[Launching Linux 'top' utility for comparison]\n");
    printf("Press 'q' to quit the top view.\n\n");
    system("top");
}

// Function for real-time CPU monitor
void realTimeCPUMonitor() {
    printf("\n[Real-Time CPU Monitor - Updates every second]\n");
    printf("Press Ctrl+C to stop.\n\n");
    while (1) {
        system("top -bn1 | grep 'Cpu(s)'");
        sleep(1);
    }
}

// Function to generate report
void generateReport() {
    FILE *fp;
    fp = fopen("system_report.txt", "w");
    if (fp == NULL) {
        printf("Error creating report file!\n");
        return;
    }

    fprintf(fp, "===== SYSTEM PERFORMANCE REPORT =====\n\n");
    fprintf(fp, "[CPU Usage]\n");
    system("top -bn1 | grep 'Cpu(s)' >> system_report.txt");
    fprintf(fp, "\n[Memory Usage]\n");
    system("free -h >> system_report.txt");
    fprintf(fp, "\n[Running Processes]\n");
    system("ps -eo pid,comm,pcpu,pmem --sort=-pcpu | head -15 >> system_report.txt");

    fclose(fp);
    printf("\nReport generated successfully: system_report.txt\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n========== PROCESS MONITORING TOOL ==========\n");
        printf("1. Display CPU Usage\n");
        printf("2. Display Memory Usage\n");
        printf("3. Display Running Processes\n");
        printf("4. Compare with Linux top Command\n");
        printf("5. Real-Time CPU Monitor\n");
        printf("6. Generate Report\n");
        printf("7. Exit Program\n");
        printf("=============================================\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCPUUsage();
                break;
            case 2:
                displayMemoryUsage();
                break;
            case 3:
                displayRunningProcesses();
                break;
            case 4:
                compareWithTop();
                break;
            case 5:
                realTimeCPUMonitor();
                break;
            case 6:
                generateReport();
                break;
            case 7:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice! Please select between 1 and 7.\n");
        }
    }

    return 0;
}
