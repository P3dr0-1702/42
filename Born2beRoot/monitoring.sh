#! bin/bash
echo "Broadcast message from $(whoami)@$(hostname) ($(tty | sed 's|/dev/||') ($(date)))"
arch=$(uname -a)
echo "\t#Architecture: ${arch}"
pCPU=$(grep "physical id" /proc/cpuinfo | sort -u |wc -l)
echo "\t#CPU physical : ${pCPU}"
vCPU=$( grep -c "processor" /proc/cpuinfo)
echo "\t#vCPU : ${vCPU}"
memU=$(free --mega | awk '$1 == "Mem:" {printf("%d/%dMB", $3, $2)}'; free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}')
echo "\t#Memory Usage: ${memU}"
avail=$(df -h --output=avail / | tail -n 1 | tr -d ' ')
size=$(df -h --output=size / | tail -n 1 | tr -d ' ')
used=$(df -h --output=pcent / | tail -n 1 | tr -d ' ')
echo "\t#Disk Usage: ${avail}/${size}B (${used})"
CPUL=$(top -bn1 | grep "Cpu(s)" | awk '{print 100 - $8 "%"}')
echo "\t#CPU load: ${CPUL}"
LstBoot=$(uptime -s)
echo "\t#Last boot: ${LstBoot}"
LMVStat=$(sudo lvs > /dev/null 2>&1 && echo -n "Yes" || echo -n "No")
echo "\t#LVM use: ${LVMStat}"
Connct=$(ss -tuln | wc -l | tr -d '\n' && echo -n "Established" || echo -n "Not Established")
echo "\t#Connections TCP: ${Connct}"
UserNbr=$(who | wc -l)
echo "\t#User log: ${UserNbr}"
IP=$(hostname -I | awk '{print $1}' | tr -d '\n')
MAC=$(ifconfig |awk '$1 == "ether" {print $2; exit}')
echo "\t#Network: IP ${IP} (${MAC})"
SUDOCMD=$(grep -i 'COMMAND' /var/log/sudo/sudo_config |wc -l)
echo "\t#Sudo : ${SUDOCMD} cmd"

