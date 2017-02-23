Imp V0.1 rule configuration:

Rules in Imp currently allow two actions: playing a local sound
file, or executing an external application.  The first major
release will also include a cross-platform internal Lua scripting
engine, which will allow you to feed script results back into the
message list and update the map.  It may be better to wait for
the internal engine before getting too ambitious, as it will
allow your scripts to be used by users on other platforms.

Rule format:

    x | Channel_name | If it matches this... | Do This! | Continue?

There are five parts to a rule:  The enabled flag, the channel
expression, the match expression, the action, and the continue
flag.  All expressions are regular expressions, which gives a lot
of flexibility in exactly what they will match.  There are
entire books written on regular expressions, and you can
do a web search for more examples, but I will try to run
down the basics below.

x (Enable):
-----------

The enable flag simply lets you enable/disable a rule without
needing to remove it from your list.  This should come in
handy for rules related to trade channels where you want to
temporarily discontinue notification of an item for sale/trade
after you have bankrupted yourself on plex and skill injectors.
:)

Channels:
---------

The channel expression identifies which channel(s) the rule
will monitor.  Since regular expressions match on substrings,
it will match any channel whose name contains the specified
expression unless you specifically use the start and end
qualifiers.

So, "Trade" (without the quoatation marks)
will match any channel that has Trade as part of its name
(i.e. "P-Trade", "Q-Trade", "Traders", etc.).  However,
the expression "^Trade$" would match *only* the channel
named "Trade", thanks to the '^' and '$' qualifiers.

Thhe caret is a special qualifier in regular expressions, when
it occurs as the first character of an expression, which means
"starts with", and the dollar sign, when at the end of an
expression, means "ends with".


Matching:
---------

The Match expression compares against the full text of a
message.  This includes the time and sender!  A full text
message looks like this:

   [ 2016.12.22 00:45:58 ] Kym Sorenson > there's a neut in iwz
   that's probably a dropper, fyi

Having the full text allows you to set up rules that are active
only at specific time frames, or that only fire when the sender
is a specific person. For example, a match of:

   >.*[Kk]hasm

will cause a rule to be matched whenever anyone says anything
including the name Khasm, whether they capitalized it or not.
Here's a breakdown of how it works:

The first character, '>', won't be matched until it sees that
character in the string, which only occurs for the first time
after the sender.  This prevents the rule from being matched
every time my own character, Khasm Kaotiqa, sends a message.

The next two characters '.*' are equivalent to the simpler
wildcard expression's '*' term that you may be used to
from command line interfaces. In regular expressions, '.*' is
shorthand for "any character, repeated any number of times,
even zero times".  This is because the '.' matches any
character, and the '*' indicates the previous character in the
regular expression may repeat or not exist at all.

Brackets in regular expressions allow you to specify a list
of characters, any one of which may match the character in the
string.  So "[Kk]" will match a capital K or a lowercase k.
You can also use ranges with brackets; "[a-zA-Z]" would match
any lowercase or uppercase letter, but not match numbers,
punctuation, or any other special characters.

If you need to match a character that is normally a reserved
character in a regular expression, you need to use the
backslash as an escape character.  For example:

   \*\*\*

would match any string that contains "***".


Action:
-------

There are currently only two implemented actions:  play, and
launch.

The 'play' action will play a sound, if it exists in Imp's
audio subdirectory.  For example:

   play test.wav

will play the sound file "test.wav" when both the channel
and the match expression of the rule are met.

Most sound files should work.  I have noticed a bug with one
of the underlying libraries that may cause really short files
to not play (the same bug seems to affect Audacity as well).
You can work around this by opening your sound file in an
editor such as Audacity and using the Generate menu option
to add a few 100 milliseconds of silence on the end of your
sound.  It will not hurt performance or slow dow subsequent
sounds, as all effects are played asynchronously.

*** NOTE:  capture processing for launch is not finished.
*** below is how it *will* work when I get an hour or so
*** to finish it.

There is also an option to launch your own application/script
from a rule.  You do this by using the 'launch' command:

   launch action.sh

To send parameters to the script or application, you can
use regular expression captures.  Some examples:

   launch action.sh \0

will call the shell script named 'action.sh', and pass the full
message text to the script.

To send only parts of the message to the script, you must
define captures in the message expression:

    (In channel expression:) ^Corp$
    (In message expression:)  >.*(http:[^ ]+)
                (In action:)  launch google-chrome \1

would, on Linux, open chrome to any web page mentioned in
your corp chat (Maybe not a good idea if you don't have the
browser on a second monitor or if your corpmates are
assholes.  <g>).  On Windows, you would need to replace
'google-chrome' with 'start'.

The parenthesis are what defines a capture, so the part
of the expression that matches "http:[^ ]+" will get put
into the first capture (\1).  You can define multiple
captures and use them in the action as \2, \3, etc.  \0
always matches the full text of the message.

Continue:
---------

The continue flag, at the far right of the expression (and enabled
by default tells Imp whether or not you want to continue processing
the rules below the current one in the event that the rule is
matched.  This allows you to give precedence to one rule (by having
it higher in your list and disabling the continue flag) when two or
more rules would match a single message.

For Example:

   x | Local | [ ]red$ | play REALLY_bad_sound.wav | _
   x | .*    | [ ]red$ | play bad_sound.wav        | x

(I'm using the underscore to mean an unchecked box here)

This rule would play a REALLY bad sound if someone in local chat
announced a red, but just a normal bad sound if someone in
any other channel announced a red.  By unchecking the continue
flag, you can make the distinction with different sounds,
instead of them both playing at once (since .* would also match
Local).

Addendum:
---------

There's more to come!  Next time I'm in a fleet, I'll try to put
together some rules that will help keep us on top of those pesky
messages from the FC.
