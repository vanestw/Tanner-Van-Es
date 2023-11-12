<div align="center">

# CSC1061 FALL 2023 CLASS PROJECT

## Instructions

</div>

*In this readme we will be referring to PowerShell, but if you are using a Mac the instructions are the same in the terminal.*

Before we can create a new directory and clone the repository onto your machine, you must do two things.

1. Go to github.com and create an account.

2. Type the following commands into PowerShell:

```bash
git config --global user.email "your school email address"
git config --global user.name "your group members names"
```

Next, go into your GitHub account and go to the following URL:

```
https://github.com/nschmidtfrcc/CSC1061FA23
```

The following screen should come up:

![CSC git screen](./Assets/csc1061-git-full-window.png)

Now navigate to the `fork` button, which looks like this:

![CSC fork button](./Assets/csc-git-fork-button.png)

Now click the arrow directly to the right of the `fork` button. Once the arrow has been pressed, you should see this:

![CSC fork button pushed](./Assets/csc-fork-button-pressed.png)

Click on the `+ Create a new fork`. Once you do that, your screen should be looking at this:

![fork screen](./Assets/fork-screen.png)

Please change the `Repository name` to that of you and your group member, for example, `Tanner_Van-Es--Eli_Blume.` Leave everything else the same and press the `Create fork` button.

Perfect! Now, you have successfully created a fork of the main repository. This newly created `fork` is where you and your partner will be working.

However, before we can do anything, we must clone a copy of our new forked repository onto our machines. First, we can create a directory to clone the repo. Type the following into PowerShell or terminal:

```bash
mkdir ClassProject
cd ClassProject
```

That created a new directory named ClassProject which you will work out of. We need to clone a copy of our Git repository to work directly with it. To do that, press the following `code` button on the front page of your newly forked repo:

![code button](./Assets/code-button-clone.png)

Ensure the `HTTPS` option is selected, then copy the link. The link should look something like this: 

```bash
https://github.com/<github-username>/<forked-repo-name>.git
```

Now reopen the PowerShell and type in this command:

```bash
git clone <the url you copied from your forked repo>
```

If you then type `ls` into PowerShell, you should see the name of your forked repository. Awesome!

Now you have a local copy of the codebase on your machine, and it can be opened via your favorite IDE; navigate to the ClassProject directory like you would any directory and start the project. You can now begin freely working on your code.

The beauty of Git is its ability to share and help *version* our code.

Three primary levels of Git are important to understand. The **local repository** (the cloned fork in your ClassProjects directory), the **staging area** (intermediate reviewing step before committing and pushing to your remote repository), and the **remote repository** (your GitHub fork).

Committing should be done frequently, like saving your project or compiling your code. 

The ***local repository*** (local repo)  is the copy of the repository on your machine (the repo we just cloned). The ***staging area*** is something we have yet to come across. After you have written some code, you can add the changes you have made to the staging area. The staging area allows the files you have changed to sit before you are ready to **commit** and **push** them into the remote repo, much like laying out the things you want to take on the bed before putting them in your suitcase. 

To add modified files into the staging area so they are ready for a commit, come back to your Terminal or PowerShell window and run:

```bash
git add <filenames>
```

You may also run:

```bash
git add .
```

The `.` refers to the current directory and will add every file within your current working directory to be tracked.

***Some IDEs will prompt you when they detect that you are in a Git repository, and if you allow the IDE, it will help abstract some of these command-line commands and run them for you through the graphical user interface. Depending on the IDE the rest of the readme might not be applicable***

It is essential that your commit message is concise and clearly explains what you have modified or added so one of your peers/group members can see what you have done. Also, these comments will be used to take your project in the grading process. Treat your commit messages as seriously as you would inline comments.

***If you are using your personal device you will need to install git onto your computer. The following instructions go though those steps.***
Next, type the following command in PowerShell:

```bash
git commit -m "Your commit message here"
```

Finally, we can push our changes into the remote repository. To do so, run:

```bash
git push origin <forked repo name>
```

# 

<div align="center">

***===NEED TO FIGURE OUT WHAT TO DO WITH THIS BLOCK===***

</div>

On Windows, first install [Git](https://git-scm.com/download/win). Then open up the program Windows PowerShell.

On Mac you will first need to install the Homebrew package manager. You can do so by opening the program Terminal and run this command:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

[Learn more about Homebrew here](https://brew.sh/)

After Homebrew is installed, you need to install the git package. To do so, just run the following command in PowerShell:

```homebrew
brew install git
```

<div align="center">

***===NEED TO FIGURE OUT WHAT TO DO WITH THIS BLOCK===***

</div>
