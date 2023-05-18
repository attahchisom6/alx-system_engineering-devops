# A puppet manifest to increaase the value of the request nginx handles

exec {'fix--for-nginx':
	provider => shell,
	command	=> 'sed -i "s/15/4096/" /etc/default/nginx'
}

# restart nginx
exec {'restarting nginx':
	provider => shell,
	command => 'service nginx restart'
}
