# Using Git at the Terminal Level
**STEP ON YOUR RIGHT FOOT, DON'T FORGET IT**

*Before you start developing, check your configuration*

git config --list #this should print all of your aggregated information

for the three-stage process (development, staging, committing)

## 1) make a .gitignore file for any visible files that you don't want to commit

`touch .gitignore ; vim .gitignore #add whatever files you want`

before you start using any git commands, if you don't know what one does, use
`git help <command>`

OR you can use the man pages

## 2) Create a repository in your local environment (if you're not pulling from an online repository)

`git init`

## 3) add any relevant files to the git directory with

`git add <arguments>`

### 3b) if you want to add all of the relevant files,

`git add -A`

### 3c) To determine the status of your repository

`git status`

### 3d) To determine any differences in the cloned version and your updated version,

`git diff`

## 4) If you're ready to update your source code, 

`git commit -m "<description>"`
`git pull origin master`
`git push origin master`

