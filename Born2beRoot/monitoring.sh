#!/bin/bash
arch=$(uname -a)
pCPU=$(grep "physical id" /proc/cpuinfo | sort -u |wc -l)
vCPU=$( grep -c "processor" /proc/cpuinfo)
memU=$(free --mega | awk '$1 == "Mem:" {printf("%d/%dMB (%.2f%%)\n", $3, $2, $3/$2*100)}')
avail=$(df -h --output=avail / | tail -n 1 | tr -d ' ')
size=$(df -h --output=size / | tail -n 1 | tr -d ' ')
used=$(df -h --output=pcent / | tail -n 1 | tr -d ' ')
CPUL=$(top -bn1 | grep "Cpu(s)" | awk '{print 100 - $8 "%"}')
LstBoot=$(uptime -s)
LMVStat=$(lvs > /dev/null 2>&1 && echo -n "Yes" || echo -n "No")
Connct=$(ss -tuln | wc -l | tr -d '\n' && echo -n " ESTABLISHED" || echo -n " NOT ESTABLISHED")
UserNbr=$(who | wc -l)
IP=$(hostname -I)
MAC=$(ip link | grep "link/ether" | awk '{print $2}')
SUDOCMD=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

wall << EOF
	#Architecture: ${arch}
	#CPU physical : ${pCPU}
	#vCPU : ${vCPU}
	#Memory Usage: ${memU}
	#Disk Usage: ${avail}/${size}B (${used})
	#CPU load: ${CPUL}
	#Last boot: ${LstBoot}
	#LVM use: ${LMVStat}
	#Connections TCP: ${Connct}
	#User log: ${UserNbr}
	#Network: IP ${IP}(${MAC})
	#Sudo : ${SUDOCMD} cmd

EOF
echo
