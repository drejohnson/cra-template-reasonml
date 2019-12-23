module type RouterConfig = {
  type route;

  let toUrl: route => string;
  let toRoute: ReasonReact.Router.url => route;
};

module Config = {
  type route =
    | Home
    | About
    | NotFound;

  let toRoute = (url: ReasonReact.Router.url) => {
    switch (url.path) {
    | [] => Home
    | ["about"] => About
    | _ => NotFound
    };
  };

  let toUrl =
    fun
    | Home => "/"
    | About => "/about"
    | NotFound => "/404";
};

module Create = (Config: RouterConfig) => {
  type route = Config.route;
  type action =
    | UpdateRoute(route);

  type state = {route};

  [@react.component]
  let make = (~children) => {
    let (state, dispatch) =
      React.useReducer(
        (_state, action) =>
          switch (action) {
          | UpdateRoute(route) => {route: route}
          },
        {
          route:
            ReasonReact.Router.dangerouslyGetInitialUrl() |> Config.toRoute,
        },
      );
    ();

    React.useEffect1(
      () => {
        let watcherID =
          ReasonReact.Router.watchUrl(url =>
            UpdateRoute(Config.toRoute(url)) |> dispatch
          );
        Some(() => ReasonReact.Router.unwatchUrl(watcherID));
      },
      [|dispatch|],
    );

    children(state.route);
  };
};

module Link = {
  [@react.component]
  let make = (~to_, ~style=?, ~className=?, ~children) => {
    let href = Config.toUrl(to_);
    let onClick = e => {
      ReactEvent.Mouse.preventDefault(e);
      ReasonReact.Router.push(href);
    };
    <a href onClick ?style ?className> children </a>;
  };
};