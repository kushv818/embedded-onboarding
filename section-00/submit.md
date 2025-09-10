(assuming we're in section-00)

❯ cd .. && ls -a | grep "\.git"
.git
.gitattributes
.github
.gitignore

git files are hidden for some reason, -a necessary

after saving

cd section-00
git status
git add submit.md
git commit -m "work done and stuff"
git push origin main