#A puppet manifest to automate the and fix error from avqurried server

exec {'To Fix the issue i found':
	command	=> 'sed -i s/phpp/php/g /var/www/html/wp-settings.php',
	path	=> '/usr/local/bin/:/bin/'
}
