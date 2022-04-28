#!/system/bin/sh

voltage_old=0
low_power_count=0

while(( low_power_count < 6 ))
do
        sleep 30
        voltage_now=$(cat /sys/class/power_supply/battery/voltage_now)
        #echo "voltage now :" $voltage_now >> /data/record_power.txt
        if [ $voltage_old -eq "0" ]; then
                ((voltage_old=voltage_now))
        fi

        ((voltage_old=(voltage_old+voltage_now)/2))

        if [ $voltage_old -le "3550000" ]; then
                ((low_power_count+=1))
        fi
done

#echo "#### ALERT : Low power !!" >> /data/record_power.txt
reboot -p
