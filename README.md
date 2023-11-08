# CSC1061 FALL 2023 CLASS PROJECT

On Windows, first install [Git](https://git-scm.com/download/win). Then open up the program Windows PowerShell.

On Mac you will first need to install the Homebrew package manager. You can do so by opening the program Terminal and run this command:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

[Learn more about Homebrew here](https://brew.sh/)

After Homebrew is installed, you need to install the git package. To do so just run the following command in Terminal:

```homebrew
brew install git
```

Before we are able to create a new directory and clone the repository onto your machine, you must do two things.

1. Go to github.com and create an account.

2. Within powershell or terminal type the following commands:

```bash
git config --global user.email "your school email address"
git config --global user.name "your group members names"
```

That that is git is configured correctly and will be attached to each commit your group makes, so we know who made which commit!

Next go into your GitHub account and go to the following url:

```
https://github.com/nschmidtfrcc/CSC1061FA23
```

You should be faced with the following screen:

![CSC git screen](./Assets/csc1061-git-full-window.png)

Now navigate to the `fork` button which looks like this:

![CSC fork button](./Assets/csc-git-fork-button.png)

Now click on the arrow directly to the right of the `fork` button. Once the arrow has been pressed you should see this:

![CSC fork button pushed](./Assets/csc-fork-button-pressed.png)

Click on the `+ Create a new fork`. Once you do that you should be looking at this:

![fork screen](./Assets/fork-screen.png)

Please change the `Repsitory name` to that of you and your group member, for example, `Tanner_Van-Es--Eli_Blume`. Leave everything else the same and press the `Create fork` button.

Perfect! Now you have successfully created a fork of the main repository. This newly created `fork` is where you and you partner will be working out of.

Before we can do anything, however, we must clone a copy of our new forked repository onto our machines. First we can create a directory in which we will clone the repo. Type the following into powershell or terminal:

```bash
mkdir ClassProject
cd ClassProject
```

That successfully created a new directory named ClassProject and moved us into it, so now our current working directory is ClassProject. Now we need to clone a copy of our Git repository in order to work directly with it. To do that, press the following `code` button on the front page of your newly forked repo:

![code button](./Assets/code-button-clone.png)

Make sure the `HTTPS` option is selected and then copy the link it shows. The link should look something like this: 

```bash
https://github.com/<github-username>/<forked-repo-name>.git
```

Now reopen up the PowerShell window that was opened earlier and type in this command:

```bash
git clone <the url you copied from your forked repo>
```

If you then type `ls` into PowerShell, you should see the name of your forked repository. Awesome!

Now you have a local copy of the codebase on your machine, and can be opened via your favorite IDE, just navigate to the ClassProject directory like you would any directory and start the project. You can now begin freely working on your code.

But the beauty of Git lies in its ability to share and help *version* our code.

There are three main levels of Git that is important to understand. The **local repository**, the **staging area**, and the **remote repository**.

The ***local repo*** is the copy of the repository on your machine (the repo we just cloned). The ***staging area*** is something we have not came across. After you have written some code you can add the changes you have made to the staging area. The staging area is a place for the files that you have made changed to to sit before you are ready to **commit** and **push** them into the remote repo. To add modified files into the staging area so they are ready for a commit, come back to your Terminal or PowerShell window and run:

```bash
git add <filenames>
```

You may also run:

```bash
git add .
```

The `.` is referring to the current directory and will add every file within your current working directory to be tracked.

Some IDEs will prompt you when they detect that you are in a Git repository, and if you allow the IDE to, through the prompts, it will help abstract some of these command-line commands and actually run them for you through the graphical user interface.

After adding files to the staging area it is a good idea to write a commit for those files so we can push them into the remote repository. It is important that your commit message clearly explains what you have modified or added, so one of your peers/group members can see what you have done.

In Terminal or PowerShell you can type in the following command:

```bash
git commit -m "Your commit message here"
```

Finally, we can push our changes into the remote repository. To do so run:

```bash
git push origin <forked repo name>
```
