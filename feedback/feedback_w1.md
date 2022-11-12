The thought to use the Twitter dataset is nice, but as the proposal has a major flaw, I have to give it 0. Please re-submit it after fixing it and mail me once done!

## Major flaw:
As clearly specified here (https://docs.google.com/document/d/10VL05FxUCQZMLb_jQfsfOMNR56ecxy0aIaqPH6KumBQ/edit), the minimum project requirements are one traversal, one covered algorithm, and one uncovered algorithm. Though I understand Kosaraju also uses dfs, but you should do a traversal separately as well (and also use a covered algorithm)

## Minor flaw:
I am not sure how you would use “smallest edges to reach target” as the heuristic. Because this is something that we want to calculate. Heuristic is something easy enough to calculate with the given data. “This algorithm assumes that there are strongly connected components”: I am not sure if this is true. You can apply the algorithm to any graph and if there are no SCCs, then it returns the list of all nodes separately (as a single node is always an SCC) Function output for SCC is incorrect The proposal started by saying that you would check if the “six handshake theory” is true but you have not covered how would you test it.