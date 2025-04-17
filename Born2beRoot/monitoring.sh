#!bin/bash
uname -a
grep "physical id" /proc/cpuinfo | sort -u |wc -l
grep -c "processor" /proc/cpuinfo
free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}'

