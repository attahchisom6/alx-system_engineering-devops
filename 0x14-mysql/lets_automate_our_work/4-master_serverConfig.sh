#!/usr/bin/env bash
#Configuring a Master slave replication

#Configuring primary or master server
sudo ufw allow from 54.209.215.95 to any port 3306
#comment the bind default connection as per requred by alx so as to avoid unnessary issues
sed -i 's/bind-address = 127.0.0.1/# bind-address = 127.0.0.1' /etc/mysql/mysql.conf.d/mysqld.cnf
#append to configure the Master
printf %s "
#Configuring Master Server
server-id = 1
log_bin = /var/log/mysql/mysql-bin.log
binlog_do_db = tyrell_corp" >> /etc/mysql/mysql.conf.d/mysqld.cnf

sudo service mysql restart

#lock the rables
mysql -uroot -p -e "FLUSH TABLE WITH READ LOCK"
#pls note down the log filename and posution of the Master fron the below commnd
var_master='$(Mysql -uroot -p -e "SHOW MASTER STATUS")'
echo $var_master

#backup the master database
mysqldump -uroot -p --all-databases --master-data > dbname.sql

#unlock the tables
mysql -uroot -p -e "UNLOCK TABLES"

#transfer backup to replication server
scp dbname.sql 54.209.205.95:/tmp/

#And we are done for naster side configuration
