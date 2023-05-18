# A puppet manifest to increaase the value of the request nginx handles

# increase value of ulimit
exec {'fix-nginx':
	provider => 'shell',
	command	=> 'sed -i "s/15/4096/" /etc/default/nginx',

	path	=> '/bin',
	before	=> Exec['restarting nginx'],
}

# restart nginx
exec {'restarting nginx':
	provider	=> 'shell',
	command => 'sudo service nginx restart',
}
