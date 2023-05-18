# A puppet manifest to increaase the value of the request nginx handles

exec {'fix-nginx':
	provider => 'shell',
	command	=> 'sed -i "s/15/4096/" /etc/default/nginx',

	path	=> '/usr/local/bin/:/bin/',
	before	=> Exec['restarting nginx'],
}

# restart nginx
exec {'restarting nginx':
	provider	=> 'shell',
	command => 'nginx restart',
	path	=> '/etc/init.d',
}
