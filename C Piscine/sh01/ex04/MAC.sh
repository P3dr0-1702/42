ifconfig | awk '$1 == "ether" {print $2}'
