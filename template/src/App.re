open ReactUtils;

module AppRouter = Router.Create(Router.Config);

[@react.component]
let make = () => {
  open Router;
  open Router.Config;
  <div>
    <nav>
      <Link to_=Config.Home> "Home"->s </Link>
      <Link to_=Config.About> "About"->s </Link>
    </nav>
    <AppRouter>
      {currentRoute =>
         Router.Config.(
           switch (currentRoute) {
           | Home => <h1> "Home"->s </h1>
           | About => <h1> "About"->s </h1>
           | NotFound => <div> "Page not found, sorry"->s </div>
           }
         )}
    </AppRouter>
  </div>;
};