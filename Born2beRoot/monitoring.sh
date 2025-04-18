#!bin/bash
echo -n "Broadcast message from $(whoami)@$(hostname) ($(tty | sed 's|/dev/||') ($(date)))"
echo -n "\t#Architecture: "; uname -a
pCPU=$(grep "physical id" /proc/cpuinfo | sort -u |wc -l)
echo -n "#CPU physical : ${pCPU}"
echo -n "#vCPU : "; grep -c "processor" /proc/cpuinfo
echo -n "#Memory Usage: "; free --mega | awk '$1 == "Mem:" {printf("%d/%dMB", $3, $2)}'; free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}'
avail=$(df -h --output=avail / | tail -n 1 | tr -d ' ')
size=$(df -h --output=size / | tail -n 1 | tr -d ' ')
used=$(df -h --output=pcent / | tail -n 1 | tr -d ' ')
echo "#Disk Usage: ${avail}/${size}B (${used})"
