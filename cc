public ActionResult Comment(int ticketId, string content)
        {
            var comment = new Comment();
            comment.CommentContent = content;
            comment.Ticket = tm.GetTicketById(ticketId);
            var currentUserPrincipal = (HttpContext.User as CustomPrincipal);
            comment.User = um.getUserById(currentUserPrincipal.UserId);
            tm.CreateComment(comment);
            return RedirectToAction("Ticket", "Home", new { id = ticketId });
        }
