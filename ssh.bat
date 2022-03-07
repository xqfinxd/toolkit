echo "git@github.com:xqfinxd/toolkit.git"

ssh-keygen.exe -t rsa -b 2048 -C "xqf2625513819@outlook.com"

:: PS > Set-Service -Name ssh-agent -StartupType automatic
ssh-agent.exe -s

ssh-add.exe C:\Users\xuqingfeng/.ssh/id_rsa