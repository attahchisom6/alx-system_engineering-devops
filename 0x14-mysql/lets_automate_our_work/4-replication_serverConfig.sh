#!/usr/bin/env bash
#This will condigure the replication server

sed -i 's/bind-address = 127.0.0.1/# bind-address = 127.0.0.1/' /etc/mysql/mysql.conf.d/mysql.cnf

printf %s "
server-id = 2
relay-log = /etc/log/mysql/mysql-relay-bin.log
binlog_do_db = tyrell_corp" >> /etc/mysql/mysql.conf.d/mysql.cnf

sudo service mysql restart

#imporr the dump file into the replica server
sudo mysql -u root -p < /tmp/dbname.sql

#set up the slave to talk to the Master
mysql -uroot -p -e "STOP SLAVE"
mysql -uroot -p -e "CHANGE MASTER TO MASTER_HOST='54.144.221.216', MASTER_USER='replica_user', MASTER_pASSWORD='web', MASTER_LOG_FILE='mysql-bin.000480', MASTER_POS=154;"

mysql -uroot -p -e "START SLAVE"



